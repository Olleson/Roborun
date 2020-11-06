//Author: Olle Frid

#include "GameController.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Vector.h"
#include <HideNSneakUnreal/HideNSneakCPPCharacter.h>
//#include <Runtime\Engine\Private\DrawDebugHelpers.cpp>

AGameController::AGameController() {
	PrimaryActorTick.bCanEverTick = true;
}

void AGameController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	//FHitResult OutHit;

	//TArray<FVector> PlayerStarts;

	//float VectorOffset = 200.f;

	//for (int i = 0; i < Players.Num(); i++) {
	//	PlayerStarts.Add(Players[i]->GetActorLocation());
	//	PlayerStarts[i].X += VectorOffset;
	//}

}

void AGameController::BeginPlay() {
	Super::BeginPlay();

	AHideNSneakCPPCharacter* tempChar;
	APlayerCameraManager* tempCamera;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHideNSneakCPPCharacter::StaticClass(), Players);
		
	for (int i = 0; i < Players.Num(); i++) {
		tempChar = Cast<AHideNSneakCPPCharacter>(Players[i]);

		if (tempChar->IsSeeker())
			Seekers.Add(Players[i]);
		else 
			Hiders.Add(Players[i]);
		
		tempCamera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
		PlayerCameras.Add(tempCamera);
	}
	//Debug checks
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Amount of Players: %i"), Players.Num()));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("Amount of Hiders: %i"), Hiders.Num()));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Amount of Seekers: %i"), Seekers.Num()));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf(TEXT("Amount of Cameras: %i"), PlayerCameras.Num()));
	}
	GiveHidersOutline();
}

void AGameController::GiveHidersOutline() {
	
}

void AGameController::DrawLinesFromSeekersToHiders() {

	TArray<FVector> SightLines;

	//For every seeker
		//for every hider
			//Add a vector going from the Hider to the Seeker
	for (AActor* seekChar : Seekers) {
		for (AActor* hideChar : Hiders) {
			SightLines.Add(hideChar->GetActorLocation() - seekChar->GetActorLocation());
		}
	}
	//DrawDebugLine();
}