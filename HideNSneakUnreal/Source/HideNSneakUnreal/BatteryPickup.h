// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 *
 */
UCLASS()
class HIDENSNEAKUNREAL_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:
	/** Sets the default values for instances of this class */
	ABatteryPickup();

	/** Required Network Scaffolding */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Server side handling of being picked up
	void PickedUpBy(APawn* Pawn) override;

	// Public accessor to BatteryPower
	float GetPower() { return BatteryPower; }

protected:
	// The amount of power the battery holds
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
		float BatteryPower;
};
