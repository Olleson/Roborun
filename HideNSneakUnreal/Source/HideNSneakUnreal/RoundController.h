//Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerStart.h"
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

	/** Required Network Scaffolding */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadWrite, Category = "Round Controller", EditAnywhere)
		//List of all players in the game.
		TArray<AHideNSneakCPPCharacter*> Players;

	UPROPERTY(BlueprintReadWrite, Category = "Round Controller", EditAnywhere)
		//List of all Hiders in the game.
		TArray<AHideNSneakCPPCharacter*> Hiders;

	UPROPERTY(BlueprintReadWrite, Category = "Round Controller", EditAnywhere)
		//List of all Seekers in the game.
		TArray<AHideNSneakCPPCharacter*> Seekers;

	UPROPERTY(BlueprintReadWrite, Category = "Round Controller", EditAnywhere)
		//List of all player starts in the game.
		TArray<APlayerStart*> PlayerStarts;

	UPROPERTY(BlueprintReadWrite, Category = "Round Controller", EditAnywhere)
		//The smallest amount of players that can be in a round before it is over.
		int MinimumAmountOfPlayers;

	UPROPERTY(BlueprintReadWrite, Category = "Round Controller", EditAnywhere)
		int AmountOfPlayersToStart;

	UFUNCTION(BlueprintCallable, Category = "Round Controller")
		//Adds a Hider to the Seeker Team
		void BPAddHiderToSeekerTeam(AHideNSneakCPPCharacter* tempChar);

	UFUNCTION(BlueprintCallable, Category = "Round Controller")
		//Adds a Seeker to the Hider Team
		void BPAddHiderToHiderTeam(AHideNSneakCPPCharacter* tempChar);

	UFUNCTION(BlueprintCallable, Category = "Round Controller")
		//Ends the current round and resets the players to Hiders
		void BPEndRound();

	UFUNCTION(BlueprintCallable, Category = "Round Controller")
		//Starts another round
		void BPStartAnotherRound();

	UFUNCTION(BlueprintCallable, Category = "Round Controller")
		//Returns the current round controller
		ARoundController* BPGetRoundController();

	UFUNCTION(BlueprintPure, Category = "Player Settings")
		float GetHidersBaseSpeed();

	UFUNCTION(BlueprintCallable, Category = "Player Settings")
		void SetHidersBaseSpeed(float inBaseSpeed);

	UFUNCTION(BlueprintPure, Category = "Player Settings")
		float GetSeekersBaseSpeed();

	UFUNCTION(BlueprintCallable, Category = "Player Settings")
		void SetSeekersBaseSpeed(float inBaseSpeed);

	UFUNCTION(BlueprintPure, Category = "Player Settings")
		float GetPlayerBaseJumpHeight();

	UFUNCTION(BlueprintCallable, Category = "Player Settings")
		void SetPlayersBaseJumpHeight(float inJumpHeight);

protected:
	//Character's max walk speed when hider
	UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly, Category = "Player Settings")
		float HidersBaseSpeed;
	//Character's max walk speed when seeker
	UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly, Category = "Player Settings")
		float SeekersBaseSpeed;
	//Character's jump Z Velocity, how high the character jumps
	UPROPERTY(VisibleAnywhere, Replicated, BlueprintReadOnly, Category = "Player Settings")
		float PlayersBaseJumpHeight;
};