//Author: Olle Frid

#include "RandomizeSeeker.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "HideNSneakCPPCharacter.h"
#include "Engine/World.h"

ARandomizeSeeker::ARandomizeSeeker() {
	PrimaryActorTick.bCanEverTick = true;
}

void ARandomizeSeeker::BeginPlay() {
	Super::BeginPlay();
}

void ARandomizeSeeker::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void RandomizeSeeker() {
	
	TArray<AActor*> FoundPlayers;

	AHideNSneakCPPCharacter* tempPlayer;

	UGameplayStatics::GetAllActorsOfClass(GEngine->GetWorld(), AHideNSneakCPPCharacter::StaticClass(), FoundPlayers);

	int randomNumber = (rand() % FoundPlayers.Num());

	for (int i = 0; i < FoundPlayers.Num(); i++) {

		if (i == randomNumber && FoundPlayers[i]->IsA(AHideNSneakCPPCharacter::StaticClass())) {

			tempPlayer = Cast<AHideNSneakCPPCharacter>(FoundPlayers[i]);

			if (tempPlayer->hasBeenSeeker == true) {
				continue;
			}
			else {
				tempPlayer->TurnIntoSeeker();
				break;
			}
		}
	}
}