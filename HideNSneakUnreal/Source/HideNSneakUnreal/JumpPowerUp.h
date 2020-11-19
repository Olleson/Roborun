// Author: Alexander Aulin

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "JumpPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API AJumpPowerUp : public APickup
{
	GENERATED_BODY()
	
public:
	AJumpPowerUp();

	void ApplyPowerUp_Implementation(APawn* Pawn) override;

	void UnApplyPowerUp_Implementation() override;

protected:
	// How much Z-axis velocity is added to the player's jump
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
		float JumpBoost;
};
