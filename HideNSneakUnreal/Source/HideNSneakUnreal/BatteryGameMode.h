// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API ABatteryGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ABatteryGameMode();

	// Start the PowerDrainTimer
	void BeginPlay() override;

	// Returns the current rate of decay (% of InitialPower per second)
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetDecayRate() { return DecayRate; }

protected:
	// How many times per second to update characters power and check game rules
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Power")
		float PowerDrainDelay;

	// Acces to the timer for recurring power draining
	FTimerHandle PowerDrainTimer;

	// The rate at which characters lose power (% of InitialPower per second)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
		float DecayRate;

private:
	// Drains the characters' power over time and updates gameplay
	void DrainPowerOverTime();
};
