// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HideNSneakGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API AHideNSneakGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHideNSneakGameModeBase();
	

public:

	AHideNSneakGameModeBase();
	void AssignRoles();
	void EndGame();
	void LoadNextRound();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
		TSubclassOf<UUserWidget> DefaultRoundCompleteWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
		UUserWidget* RoundCompleteWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
		TSubclassOf<UUserWidget> DefaultGameCompleteWidget;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
		UUserWidget* GameCompleteWidget;

private:

	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Rounds")
		TArray<FString> Rounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Players")
		TArray<FString> Players;
	
	APlayerController* Controllers[];

	int32 CurrentRoundIndex;
	FString NextRound;

	void CheckRound();

};
