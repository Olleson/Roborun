// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "Pickup.h"
#include "BatteryPickup.h"

//////////////////////////////////////////////////////////////////////////
// ACPPCharacter

ACPPCharacter::ACPPCharacter()
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

	//Set a default value for the sphere radius
	CollectionSphereRadius = 200.0f;

	//Create the collection Sphere
	CollectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionSphere"));
	CollectionSphere->SetupAttachment(RootComponent);
	CollectionSphere->SetSphereRadius(CollectionSphereRadius);

	//Set a default value for the character's initial power level
	InitialPower = 2000.0f;
	CurrentPower = InitialPower;

	// Default values for controlling movement speed
	BaseSpeed = 10.0f;
	SpeedFactor = 0.75f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ACPPCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACPPCharacter, CollectionSphereRadius);
	DOREPLIFETIME(ACPPCharacter, InitialPower);
	DOREPLIFETIME(ACPPCharacter, CurrentPower);
}

//////////////////////////////////////////////////////////////////////////
// Input

void ACPPCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPPCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ACPPCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ACPPCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ACPPCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ACPPCharacter::TouchStopped);

	// Handle collecting pickups
	PlayerInputComponent->BindAction("CollectPickups", IE_Pressed, this, &ACPPCharacter::CollectPickups);
}

void ACPPCharacter::CollectPickups()
{
	//Ask the Server to collect pickups
	ServerCollectPickups();
}

bool ACPPCharacter::ServerCollectPickups_Validate()
{
	return true;
}

void ACPPCharacter::ServerCollectPickups_Implementation() {
	if (HasAuthority()) {
		float TotalPower = 0.0f;

		TArray<AActor*> CollectedActors;
		CollectionSphere->GetOverlappingActors(CollectedActors);

		for (size_t i = 0; i < CollectedActors.Num(); i++)
		{
			APickup* const TestPickup = Cast<APickup>(CollectedActors[i]);
			if (TestPickup != NULL && !TestPickup->IsPendingKill() && TestPickup->IsActive()) {
				if (ABatteryPickup* TestBattery = Cast<ABatteryPickup>(TestPickup)) {
					TotalPower += TestBattery->GetPower();
				}
				TestPickup->PickedUpBy(this);
				TestPickup->SetActive(false);
			}
		}
		if (!FMath::IsNearlyZero(TotalPower, 0.001f)) {
			UpdatePower(TotalPower);
		}
	}
}

void ACPPCharacter::UpdatePower(float DeltaPower)
{
	if (HasAuthority()) {
		CurrentPower += DeltaPower;

		GetCharacterMovement()->MaxWalkSpeed = BaseSpeed + SpeedFactor * CurrentPower;

		// Fake the rep notify to make this happen on the listen Server (which doesn't get the rep notify automatically) as well as the Clients
		OnRep_CurrentPower();
	}
}

void ACPPCharacter::OnRep_CurrentPower()
{
	PowerChangeEffect();
}

void ACPPCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ACPPCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ACPPCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACPPCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ACPPCharacter::MoveForward(float Value)
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

void ACPPCharacter::MoveRight(float Value)
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

