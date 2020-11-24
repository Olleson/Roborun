// Author: Alexander Aulin

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Settings")
		float HidersBaseSpeed;
	//Character's max walk speed when seeker
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Settings")
		float SeekersBaseSpeed;
	//Character's jump Z Velocity, how high the character jumps
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Settings")
		float PlayersBaseJumpHeight;

private:



};
