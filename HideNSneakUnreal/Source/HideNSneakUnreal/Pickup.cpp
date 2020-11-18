//Author: Abdi Abdifatah
//Co Author: Oskar Johansson
// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "Net/UnrealNetwork.h"

APickup::APickup() {
	// Tell Unreal Engine to replicate this actor
	bReplicates = true;

	// Pickups do not need to tick every frame
	PrimaryActorTick.bCanEverTick = false;

	// StaticMeshActor disables overlap events by default, which we need to re-enable
	GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

	if (HasAuthority()) {
		bIsActive = true;
	}

	// Default Respawn Settings
	Respawns = true;
	RespawnDelay = 60.0;
	PowerUpDuration = 10.0;
}

void APickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickup, bIsActive);
}

void APickup::OnRep_IsActive() {
	if (bIsActive) {
		GetStaticMeshComponent()->SetVisibility(true);
		GetStaticMeshComponent()->SetGenerateOverlapEvents(true);
		GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		GetStaticMeshComponent()->SetVisibility(false);
		GetStaticMeshComponent()->SetGenerateOverlapEvents(false);
		GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
}

void APickup::ClientOnPickedUpBy_Implementation(APawn* Pawn)
{
	PickupInstigator = Pawn;
	WasCollected();
}

void APickup::PickedUpBy(APawn* Pawn)
{
	if (HasAuthority()) {
		PickupInstigator = Pawn;
		ClientOnPickedUpBy(Pawn);
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

void APickup::WasCollected_Implementation()
{
	SetActive(false);
	if (HasAuthority()) {
		OnRep_IsActive();
	}
}
