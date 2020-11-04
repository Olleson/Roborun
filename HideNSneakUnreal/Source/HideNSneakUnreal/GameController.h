//Author: Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/PlayerCameraManager.h"
#include <HideNSneakUnreal/HideNSneakCPPCharacter.h>
#include "GameController.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//List of all players in the game.
	UPROPERTY(VisibleAnywhere)
		TArray<AActor*> Players;
	//List of all Hiders in the game.
	UPROPERTY(VisibleAnywhere)
		TArray<AActor*> Hiders;
	//List of all Seekers in the game.
	UPROPERTY(VisibleAnywhere)
		TArray<AActor*> Seekers;
	//List of all players' cameras.
	UPROPERTY(VisibleAnywhere)
		TArray<APlayerCameraManager*> PlayerCameras;
	//Call this to give all Hiders an outline. 
	UFUNCTION()
		void GiveHidersOutline();
	UFUNCTION()
		void DrawLinesFromSeekersToHiders();
};