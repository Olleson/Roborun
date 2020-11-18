// Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "HideNSneakCPPCharacter.h"
#include "MovementSpeedPowerUp.generated.h"

/**
 * 
 */
class AHideNSneakCPPCharacter;

UCLASS()
class HIDENSNEAKUNREAL_API AMovementSpeedPowerUp : public APickup
{
	GENERATED_BODY()

public:
	AMovementSpeedPowerUp();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (AllowPrivateAcces = "true"))
		float MovementSpeedBoost;

	void ApplyPowerUp_Implementation(APawn* Pawn) override;

	void UnApplyPowerUp_Implementation() override;
};
