// Author: Alexander Aulin

#include "HideNSneakCPPCharacter.h"
#include "Camera/CameraComponent.h"
#include "Roundcontroller.h"
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
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

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

	// Default values for controlling movement speed
	HiderBaseSpeed = 600.0;
	SeekerBaseSpeed = 666.0;
	BaseJumpHeight = 600.0;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = BaseJumpHeight;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = HiderBaseSpeed;

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

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset to avoid direct content references in C++
}

void AHideNSneakCPPCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AHideNSneakCPPCharacter::OnCompHit);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AHideNSneakCPPCharacter::OnOverlapBegin);

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("RoundController")), RoundControllerActors);
	for (AActor* Actor : RoundControllerActors) {
		RC = Cast<ARoundController>(Actor);
	}
}

void AHideNSneakCPPCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHideNSneakCPPCharacter, bIsSeeker);
	DOREPLIFETIME(AHideNSneakCPPCharacter, IsDecoy);
	DOREPLIFETIME(AHideNSneakCPPCharacter, Score);
	DOREPLIFETIME(AHideNSneakCPPCharacter, WhoTaggedMe);
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
	PlayerInputComponent->BindAction("ConsumePowerUp", IE_Released, this, &AHideNSneakCPPCharacter::ConsumePowerUp);

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

void AHideNSneakCPPCharacter::ServerCaptureHider_Implementation(AHideNSneakCPPCharacter* Hider, AHideNSneakCPPCharacter* Tagger)
{
	if (HasAuthority() && !Hider->IsSeeker()) {
		Hider->WhoTaggedMe = Tagger;
		Hider->BecomeSeeker();

		//if (Hider == this) {
		//	// Fake the On rep notify for the listen server if it is a hider that gets captured,
		//	// as the Server doesn't get on rep notify automatically
		//	OnRep_IsSeeker();
		//}
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

void AHideNSneakCPPCharacter::ClientAddScore_Implementation(AHideNSneakCPPCharacter* Scorer, int ScoreToAdd, int ScoreMultiplier)
{
	ServerAddScore(Scorer, ScoreToAdd, ScoreMultiplier);
}

void AHideNSneakCPPCharacter::ServerAddScore_Implementation(AHideNSneakCPPCharacter* Scorer, int ScoreToAdd, int ScoreMultiplier)
{
	if (HasAuthority()) {
		Scorer->Score += (ScoreToAdd * ScoreMultiplier);
	}
}

float AHideNSneakCPPCharacter::GetBaseSpeed()
{
	if (bIsSeeker) { return SeekerBaseSpeed; }
	else
	{
		return HiderBaseSpeed;
	}
}

float AHideNSneakCPPCharacter::GetBaseJumpHeight()
{
	return BaseJumpHeight;
}

void AHideNSneakCPPCharacter::CollectPickup(APickup* Pickup)
{
	/*if (CollectedPowerUp != nullptr) {
		delete CollectedPowerUp;
	}*/
	CollectedPowerUp = new PowerUpInventoryItem(this, Pickup);
	UpdatePowerUpIcon();
	Pickup->PickedUpBy(this);
}

UTexture2D* AHideNSneakCPPCharacter::GetCollectedPowerUpIcon()
{
	if (CollectedPowerUp != nullptr) {
		return CollectedPowerUp->GetPickUpIcon();
	}
	return nullptr;
}

void AHideNSneakCPPCharacter::SetSilentFootsteps_Implementation(bool inSilentFootsteps)
{
}

void AHideNSneakCPPCharacter::SetMeshVisibility_Implementation(bool inVisibility)
{
}

void AHideNSneakCPPCharacter::ConsumePowerUp_Implementation()
{
	ServerConsumePowerUp();
}

void AHideNSneakCPPCharacter::ServerConsumePowerUp_Implementation()
{
	//if (HasAuthority()) {
	if (CollectedPowerUp != NULL) {
		CollectedPowerUp->ApplyPickUp();
		ClearPowerUpIcon();
		CollectedPowerUp = NULL;
	}
	//}
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
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Ive become seeker")));
		ServerBecomeSeeker();
		ClearPowerUpIcon();
	}
}

void AHideNSneakCPPCharacter::ServerBecomeSeeker_Implementation()
{
	bIsSeeker = true;
	if (CollectedPowerUp != NULL) {
		delete CollectedPowerUp;
		CollectedPowerUp = NULL;
	}
	if (HasAuthority()) {
		OnRep_IsSeeker();
	}
}

void AHideNSneakCPPCharacter::ResetPlayersToHiders_Implementation()
{
	ServerResetPlayersToHiders();
}

void AHideNSneakCPPCharacter::ClientTaggerScore_Implementation(AHideNSneakCPPCharacter* Tagger)
{
	ServerTaggerScore(Tagger);
}

void AHideNSneakCPPCharacter::ServerTaggerScore_Implementation(AHideNSneakCPPCharacter* Tagger)
{
	//if (RC != NULL && HasAuthority()) {
	//	if (RC->Seekers.Num() <= 3) {
	//		Tagger->ClientAddScore(Tagger, 5, RC->ScoreMultiplier);
	//	}
	//	else {
	//		Tagger->ClientAddScore(Tagger, 2, RC->ScoreMultiplier);
	//	}
	//}
}

//void AHideNSneakCPPCharacter::ClientAddTaggingScore_implementation(AHideNSneakCPPCharacter* Tagger)
//{
//	ServerAddTaggingScore(Tagger);
//}
//
//void AHideNSneakCPPCharacter::ServerAddTaggingScore_Implementation(AHideNSneakCPPCharacter* Tagger)
//{
//	if (RC != NULL && HasAuthority()) {
//		if (RC->Seekers.Num() <= 3) {
//			Tagger->ClientAddScore(Tagger, 5, RC->ScoreMultiplier);
//		}
//		else {
//			Tagger->ClientAddScore(Tagger, 2, RC->ScoreMultiplier);
//		}
//	}
//}

void AHideNSneakCPPCharacter::ServerResetPlayersToHiders_Implementation()
{
	if (HasAuthority()) {
		UWorld* World = GetWorld();
		check(World);
		for (FConstControllerIterator It = World->GetControllerIterator(); It; ++It)
			if (APlayerController* PlayerController = Cast<APlayerController>(*It))
				if (AHideNSneakCPPCharacter* Character = Cast<AHideNSneakCPPCharacter>(PlayerController->GetPawn()))
					Character->BecomeHider();
	}
}


//make character go stealth + spawn a decoy character
void AHideNSneakCPPCharacter::UseDecoyAbility_Implementation() {
	if (DecoyAvailible) {
		//timer for delaying when the other part of the function is called
		//GetWorldTimerManager().SetTimer(StealthTimerHandle, this, &AHideNSneakCPPCharacter::DecoyStealthOver_Implementation, StealthDuration, false); //local
		if (Decoy != NULL) {
			DecoyAvailible = false;
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("If decoy passed")));
			if (GetWorld()) {
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("If uworld passed")));
				FActorSpawnParameters SpawnParameters; //local
				SpawnParameters.Owner = this;  //local
				SpawnParameters.Instigator = GetInstigator(); //local
				FTransform Decoytransform = this->GetActorTransform(); //local
				FVector DecoyVelocity = this->GetVelocity(); //local
				//AHideNSneakCPPCharacter * const DecoyActor = World->SpawnActor<AHideNSneakCPPCharacter>(Decoy, Spawntransform, SpawnParameters); //server
				//DecoyActor->SetLifeSpan(DecoyDuration); //server
				//DecoyActor->GetCharacterMovement()->Velocity = DecoyVelocity; //server
				//DecoyActor->MovementValue = 1.0f;  //server
				//DecoyActor->SetActorTickEnabled(true); //server
				if (this->GetInputAxisValue("MoveForward") != 0 || this->GetInputAxisValue("MoveRight") != 0) {
					ServerDecoyAbility(this, Decoytransform, DecoyVelocity, 1.0f);
				}
				else {
					ServerDecoyAbility(this, Decoytransform, DecoyVelocity, 0.0f);
				}
				GetWorldTimerManager().SetTimer(DecoyCooldownHandle, this, &AHideNSneakCPPCharacter::DecoyCooldownOver_Implementation, DecoyCooldown, false);//local
			}
		}
	}
}

//Turning the referenced character back to visible for all clients
void AHideNSneakCPPCharacter::ServerDecoyStealthOver_Implementation(AHideNSneakCPPCharacter* MyActor)
{
	if (HasAuthority()) {
		MyActor->SetActorHiddenInGame(false);
	}
}

//server side for handling the making of the character go stealth + spawn a decoy character
void AHideNSneakCPPCharacter::ServerDecoyAbility_Implementation(AHideNSneakCPPCharacter* SpawnActor, FTransform DecoyTransform, FVector DecoyVelocity, float MovementValue)
{
	if (HasAuthority()) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("If has authority server passed")));
		//SpawnActor->SetActorHiddenInGame(true);
		if (GetWorld()) {
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("If getworld server passed")));
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = SpawnActor;
			AHideNSneakCPPCharacter* DecoyActor = GetWorld()->SpawnActor<AHideNSneakCPPCharacter>(Decoy, DecoyTransform, SpawnParameters);
			if (DecoyActor) {
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("If decoyactor server passed")));
				DecoyActor->MoveIgnoreActorAdd(SpawnActor);
				SpawnActor->MoveIgnoreActorAdd(DecoyActor);
				DecoyActor->SetLifeSpan(DecoyDuration);
				DecoyActor->GetCharacterMovement()->Velocity = DecoyVelocity;
				DecoyActor->IsDecoy = true;
				if (MovementValue != 0.0f) {
					DecoyActor->DecoyMovementValue = MovementValue;
					DecoyActor->SetActorTickEnabled(true);
				}
			}
		}
	}
}

//make charcter go unstealth.
void AHideNSneakCPPCharacter::DecoyStealthOver_Implementation()
{
	ServerDecoyStealthOver(this);
	GetWorldTimerManager().ClearTimer(StealthTimerHandle);
	GetWorldTimerManager().ClearTimer(DecoyTimerHandle);
}

//clears the timer for the cooldown reset and makes the decoy ability availible again
void AHideNSneakCPPCharacter::DecoyCooldownOver_Implementation()
{
	DecoyAvailible = true;
	GetWorldTimerManager().ClearTimer(DecoyCooldownHandle);
}

//moves the decoy 
void AHideNSneakCPPCharacter::MoveDecoy_Implementation()
{
	if ((Controller != NULL))
	{
		AddMovementInput(this->GetActorForwardVector(), DecoyMovementValue);
	}
}

void AHideNSneakCPPCharacter::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(AHideNSneakCPPCharacter::StaticClass()) && OtherActor != this && !Cast<AHideNSneakCPPCharacter>(OtherActor)->bIsSeeker && bIsSeeker) {
		targetTagMechanic = Cast<AHideNSneakCPPCharacter>(OtherActor);
		ServerCaptureHider(targetTagMechanic, this);
	}
}

void AHideNSneakCPPCharacter::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bIsSeeker) {
		if (APickup* Pickup = Cast<APickup>(OtherActor)) {
			CollectPickup(Pickup);
		}
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