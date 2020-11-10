//Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoundController.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API ARoundController : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	ARoundController();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	//List of all players in the game.
		TArray<AHideNSneakCPPCharacter*> Players;

	UPROPERTY(EditAnywhere)
	//List of all Hiders in the game.
		TArray<AHideNSneakCPPCharacter*> Hiders;

	UPROPERTY(EditAnywhere)
	//List of all Seekers in the game.
		TArray<AHideNSneakCPPCharacter*> Seekers;

	UPROPERTY(EditAnywhere)
	//List of all players in the game.
		int MinimumAmountOfPlayers;

	UFUNCTION(Category = "Round Controller")
	//Fills the arrays Players, Hiders, & Seekers.
		void FillArrays();

	UFUNCTION(Category = "Round Controller")
	//Adds the Hider to the Seeker team.
		void AddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar);
	//Ends the round
	UFUNCTION(Category = "Round Controller")
		void EndRound();

	UFUNCTION(BlueprintCallable, Category = "Round Controller")
	//Blueprint test function bla bla bla
		void BPAddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar);
};