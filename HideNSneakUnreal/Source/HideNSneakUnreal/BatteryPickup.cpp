// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryPickup.h"
#include "Net/UnrealNetwork.h"

ABatteryPickup::ABatteryPickup() {
	// Sync movement between server and client
	bStaticMeshReplicateMovement = true;
	// This pickup is physics enabled and can move
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetSimulatePhysics(true);

	// Set a default value for the power
	BatteryPower = 20.0f;
}

void ABatteryPickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABatteryPickup, BatteryPower);
}

void ABatteryPickup::PickedUpBy(APawn* Pawn)
{
	Super::PickedUpBy(Pawn);

	if (HasAuthority()) {
		// Give the clients time to play vfx etc. before destroying the battery
		SetLifeSpan(2.0f);
	}
}
