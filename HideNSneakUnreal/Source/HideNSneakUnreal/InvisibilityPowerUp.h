// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "InvisibilityPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API AInvisibilityPowerUp : public APickup
{
	GENERATED_BODY()
	
public:
	void ApplyPowerUp_Implementation(APawn* Pawn) override;

	void UnApplyPowerUp_Implementation() override;
};
