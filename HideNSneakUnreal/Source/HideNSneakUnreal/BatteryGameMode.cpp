// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryGameMode.h"
#include "CPPCharacter.h"

ABatteryGameMode::ABatteryGameMode()
{
	// Default Decay Rate
	DecayRate = 0.02f;

	// Default value for how frequently to drain power
	PowerDrainDelay = 0.25f;
}

void ABatteryGameMode::BeginPlay()
{
	GetWorldTimerManager().SetTimer(PowerDrainTimer, this, &ABatteryGameMode::DrainPowerOverTime, PowerDrainDelay, true);
}

void ABatteryGameMode::DrainPowerOverTime()
{
	// Access the world to get to the players
	UWorld* World = GetWorld();
	check(World);

	for (FConstControllerIterator It = World->GetControllerIterator(); It; ++It) {
		if (APlayerController* PlayerController = Cast<APlayerController>(*It)) {
			if (ACPPCharacter* BatteryCharacter = Cast<ACPPCharacter>(PlayerController->GetPawn())) {
				if (BatteryCharacter->GetCurrentPower() > 0) {
					BatteryCharacter->UpdatePower(PowerDrainDelay * -DecayRate * BatteryCharacter->GetInitialPower());
				}
			}
		}
	}
}