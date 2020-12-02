//Author: Abdi Abdifatah
//Co Authors: Oskar Johansson, Alexander Aulin


#include "Pickup.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

APickup::APickup(const FObjectInitializer& OI) : Super(OI) {
	// Tell Unreal Engine to replicate this actor
	bReplicates = true;

	// Pickups do not need to tick every frame
	PrimaryActorTick.bCanEverTick = false;

	// Initialize Mesh
	SkeletalMeshComponent = OI.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	SetRootComponent(SkeletalMeshComponent);
	SkeletalMeshComponent->SetGenerateOverlapEvents(false);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Initialize Collision Box
	BoxComponent = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Collider"));
	BoxComponent->SetupAttachment(SkeletalMeshComponent);
	BoxComponent->SetGenerateOverlapEvents(true);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (HasAuthority()) {
		bIsActive = true;
	}

	// Default Respawn Settings
	Respawns = true;
	RespawnDelay = 60.0;
	PowerUpDuration = 10.0;

	// No default socket to attach particles to
	SocketToAttachParticlesTo = NAME_None;
}

void APickup::BeginPlay()
{
	AActor::BeginPlay();
	BoxComponent->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	OnSpawn();
}

void APickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickup, bIsActive);
}

bool APickup::DoesSpawnParticles()
{
	return SpawnsParticles;
}

void APickup::OnRep_IsActive() {
	if (bIsActive) {
		BoxComponent->SetGenerateOverlapEvents(true);
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		BoxComponent->SetGenerateOverlapEvents(false);
		BoxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		if (Respawns) {
			GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &APickup::RespawnPickup, RespawnDelay, false);
		}
	}
}

void APickup::RespawnPickup()
{
	SetActive(true);
	if (HasAuthority()) {
		OnRep_IsActive();
	}
	OnSpawn();
}

void APickup::ClientOnPickedUpBy_Implementation(ACharacter* Character)
{
	PickupInstigator = Character;
	WasCollected();
	OnPickedUp();
}

void APickup::PickedUpBy(ACharacter* Character)
{
	if (HasAuthority()) {
		PickupInstigator = Character;
		ClientOnPickedUpBy(Character);
	}
}

void APickup::ApplyPowerUp_Implementation(ACharacter* Character)
{
	
}

void APickup::ClientApplyPowerUp_Implementation(ACharacter* Character)
{
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Requesting Server to replicate power up activation"));
	if (SpawnsParticles && IsValid(Particles)) {
		UParticleSystemComponent* ParticlesComponent;
		if (AttachParticlesToCharacter) {
			ParticlesComponent = UGameplayStatics::SpawnEmitterAttached(Particles, Character->GetMesh(), SocketToAttachParticlesTo);
		}
		else
		{
			ParticlesComponent = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particles, Character->GetActorLocation(), Character->GetActorRotation(), true);
		}
		ParticleComponents.push(ParticlesComponent);
	}
	ApplyPowerUp(Character);
}

void APickup::UnApplyPowerUp_Implementation()
{
	if (!Respawns) { Destroy(); }
	if (SpawnsParticles && IsValid(ParticleComponents.front())) {
		ParticleComponents.front()->Deactivate();
		ParticleComponents.front()->DestroyComponent();
		ParticleComponents.pop();
	}
}

bool APickup::IsActive() {
	return bIsActive;
}

void APickup::SetActive(bool NewPickupState) {
	//Using HasAuthority since newer versions of Unreal Engine has Role set as a private member
	if (HasAuthority()) {
		bIsActive = NewPickupState;
	}
}

UTexture2D* APickup::GetPickupIcon()
{
	return PickupIcon;
}

void APickup::WasCollected_Implementation()
{
	SetActive(false);
	if (HasAuthority()) {
		OnRep_IsActive();
	}
}