//Olle Frid

#include "RoundController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "HideNSneakCPPCharacter.h"

ARoundController::ARoundController() { }

void ARoundController::BeginPlay() { Super::BeginPlay(); }

void ARoundController::BPAddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar) {

	if (Hiders.Contains(tempChar)) {
		Hiders.Remove(tempChar);
		Seekers.Add(tempChar);
	}
}

void ARoundController::BPAddHiderToHiderTeam(AHideNSneakCPPCharacter* tempChar) {
	if (!Hiders.Contains(tempChar))
		Hiders.Add(tempChar);
	if (Seekers.Contains(tempChar))
		Seekers.Remove(tempChar);
	if (!Players.Contains(tempChar))
		Players.Add(tempChar);
}

void ARoundController::BPEndRound() { Players[0]->ServerResetPlayersToHiders(); }

void ARoundController::BPStartAnotherRound() {
	//Move players to start points
	//Perform start round functionality
}

ARoundController* ARoundController::BPGetRoundController() { return this; }