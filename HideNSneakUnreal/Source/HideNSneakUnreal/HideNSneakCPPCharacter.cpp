// Fill out your copyright notice in the Description page of Project Settings.

#include "HideNSneakCPPCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayTagsModule.h"
#include "GameplayTagsSettings.h"
#include "GameplayTags.h"
#include "GameplayTagsManager.h"
#include "GameFramework/Actor.h"

//////////////////////////////////////////////////////////////////////////
// AHideNSneakCPPCharacter

AHideNSneakCPPCharacter::AHideNSneakCPPCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Characters are hiders by default
	bIsSeeker = false;

	// Default values for controlling movement speed
	BaseSpeed = 10.0f;
	SpeedFactor = 0.75f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AHideNSneakCPPCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AHideNSneakCPPCharacter::OnCompHit);
}

void AHideNSneakCPPCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AHideNSneakCPPCharacter, bIsSeeker);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AHideNSneakCPPCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("BecomeSeeker", IE_Released, this, &AHideNSneakCPPCharacter::BecomeSeeker);
	PlayerInputComponent->BindAction("ResetPlayersToHiders", IE_Released, this, &AHideNSneakCPPCharacter::ResetPlayersToHiders);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHideNSneakCPPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHideNSneakCPPCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AHideNSneakCPPCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AHideNSneakCPPCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AHideNSneakCPPCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AHideNSneakCPPCharacter::TouchStopped);
}

void AHideNSneakCPPCharacter::ServerCaptureHider_Implementation(AHideNSneakCPPCharacter* Hider)
{
	if (HasAuthority() && !Hider->IsSeeker()) {
		Hider->ServerBecomeSeeker_Implementation();
		if (Hider == this) {
			// Fake the On rep notify for the listen server if it is a hider that gets captured,
			// as the Server doesn't get on rep notify automatically
			OnRep_IsSeeker();
		}
	}
}

void AHideNSneakCPPCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AHideNSneakCPPCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AHideNSneakCPPCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHideNSneakCPPCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AHideNSneakCPPCharacter::BecomeHider_Implementation()
{
	if (bIsSeeker) {
		ServerBecomeHider();
	}
}

void AHideNSneakCPPCharacter::ServerBecomeHider_Implementation()
{
	bIsSeeker = false;
	if (HasAuthority()) {
		OnRep_IsSeeker();
	}
}

void AHideNSneakCPPCharacter::BecomeSeeker_Implementation()
{
	if (!bIsSeeker) {
		ServerBecomeSeeker();
	}
}

void AHideNSneakCPPCharacter::ServerBecomeSeeker_Implementation()
{
	bIsSeeker = true;
	if (HasAuthority()) {
		OnRep_IsSeeker();
	}
}

void AHideNSneakCPPCharacter::ResetPlayersToHiders_Implementation()
{
	ServerResetPlayersToHiders();
}

void AHideNSneakCPPCharacter::ServerResetPlayersToHiders_Implementation()
{
	if (HasAuthority()) {
		UWorld* World = GetWorld();
		check(World);
		for (FConstControllerIterator It = World->GetControllerIterator(); It; ++It) {
			if (APlayerController* PlayerController = Cast<APlayerController>(*It)) {
				if (AHideNSneakCPPCharacter* Character = Cast<AHideNSneakCPPCharacter>(PlayerController->GetPawn())) {
					Character->BecomeHider();
				}
			}
		}
	}
}

void AHideNSneakCPPCharacter::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(AHideNSneakCPPCharacter::StaticClass()) && OtherActor != this && !Cast<AHideNSneakCPPCharacter>(OtherActor)->bIsSeeker && bIsSeeker) {
		targetActor = OtherActor;
		targetTagMechanic = Cast<AHideNSneakCPPCharacter>(targetActor);
		ServerCaptureHider(targetTagMechanic);
	}
}

void AHideNSneakCPPCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AHideNSneakCPPCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}