//Olle Frid

#include "RoundController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "HideNSneakCPPCharacter.h"

ARoundController::ARoundController() { }

void ARoundController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARoundController, HidersBaseSpeed);
	DOREPLIFETIME(ARoundController, SeekersBaseSpeed);
	DOREPLIFETIME(ARoundController, PlayersBaseJumpHeight);
}

void ARoundController::BeginPlay() { Super::BeginPlay(); }

void ARoundController::BPAddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar) {

	if (Hiders.Contains(tempChar)) {
		Hiders.Remove(tempChar);
		Seekers.Add(tempChar);
	}
}

void ARoundController::BPAddHiderToHiderTeam(AHideNSneakCPPCharacter* tempChar) {
	if (!tempChar->IsDecoy) {
		if (!Hiders.Contains(tempChar))
			Hiders.Add(tempChar);
		if (Seekers.Contains(tempChar))
			Seekers.Remove(tempChar);
		/*if (!Players.Contains(tempChar))
			Players.Add(tempChar);*/
	}
}

void ARoundController::BPEndRound() {
	Players[0]->ServerResetPlayersToHiders();
}

void ARoundController::BPStartAnotherRound() {
	//Move players to start points
	//Perform start round functionality
}

ARoundController* ARoundController::BPGetRoundController() { return this; }

float ARoundController::GetHidersBaseSpeed()
{
	return HidersBaseSpeed;
}

void ARoundController::SetHidersBaseSpeed(float inBaseSpeed)
{
	HidersBaseSpeed = inBaseSpeed;
}

float ARoundController::GetSeekersBaseSpeed()
{
	return SeekersBaseSpeed;
}

void ARoundController::SetSeekersBaseSpeed(float inBaseSpeed)
{
	SeekersBaseSpeed = inBaseSpeed;
}

float ARoundController::GetPlayerBaseJumpHeight()
{
	return PlayersBaseJumpHeight;
}

void ARoundController::SetPlayersBaseJumpHeight(float inJumpHeight)
{
	PlayersBaseJumpHeight = inJumpHeight;
}
