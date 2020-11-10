//Olle Frid

#include "RoundController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "HideNSneakCPPCharacter.h"

ARoundController::ARoundController() {
	PrimaryActorTick.bCanEverTick = true;
}

void ARoundController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (TimeWhenRoundEnds == AActor::GetGameTimeSinceCreation()){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("SPELSLUT")));
	}
}

void ARoundController::BeginPlay()
{
	Super::BeginPlay();

	TimeWhenRoundEnds = AActor::GetGameTimeSinceCreation() + GameLengthInSeconds;

	//To fill Players, an array with HideNSneakCPPCharacters, we need to first go through an array FoundActors
	//and then converrt it to an array of HNSCPPCs (GetAllActorsOfClass is good but wonky)
	//TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHideNSneakCPPCharacter::StaticClass(), FoundActors);

	//for (int i = 0; i < FoundActors.Num(); i++)
	//	Players.Add(Cast<AHideNSneakCPPCharacter>(FoundActors[i]));
	//
	//FillArrays();
}

void ARoundController::FillArrays() {

	//Empty them out first
	Hiders.Empty();
	Seekers.Empty();

	for (int i = 0; i < Players.Num(); i++) {

		Hiders.Add(Players[i]);
		//If Players[i] is a Seeker, add it to Seekers, else add it to Hiders
		//Players[i]->IsSeeker() ? Seekers.Add(Players[i]) : Hiders.Add(Players[i]);

		//if (Players[i]->IsSeeker()) {
		//	//if (!Seekers.Contains(Players[i]))
		//		Seekers.Add(Players[i]);

		//	//if(Hiders.Contains(Players[i]))
		//		//Hiders.Remove(Players[i]);
		//} else {
		//	//if (!Hiders.Contains(Players[i]))
		//		Hiders.Add(Players[i]);

		//	//if (Seekers.Contains(Players[i]))
		//		//Seekers.Remove(Players[i]);
		//}	
	}
}

void ARoundController::AddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar){

	if (Hiders.Contains(tempChar)) {
		Hiders.Remove(tempChar);
		Seekers.Add(tempChar);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("A Hider has been tagged! Amount of Hiders: %i, Amount of Seekers: %i"), Hiders.Num(), Seekers.Num()));
	}
	if (Hiders.Num() == MinimumAmountOfPlayers)
		EndRound();
}

void ARoundController::BPAddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar) {

	if (Hiders.Contains(tempChar)) {
		Hiders.Remove(tempChar);
		Seekers.Add(tempChar);

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%i %i"), Hiders.Num(), MinimumAmountOfPlayers));
		
		if (Hiders.Num() == MinimumAmountOfPlayers)
			EndRound();
	}
}

void ARoundController::EndRound() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("GAME OVER %i %i"), Hiders.Num(), MinimumAmountOfPlayers));

	Players[0]->ResetPlayersToHiders();

	FillArrays();
}