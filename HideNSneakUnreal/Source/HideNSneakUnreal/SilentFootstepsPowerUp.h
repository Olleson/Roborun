// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "SilentFootstepsPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API ASilentFootstepsPowerUp : public APickup
{
	GENERATED_BODY()
	
public:
	ASilentFootstepsPowerUp(const FObjectInitializer& OI);

protected:

	void ApplyPowerUp(ACharacter* Character) override;

	void UnApplyPowerUp() override;
};
