// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HideNSneakCPPCharacter.h"
#include "Pickup.h"

/**
 * 
 */
class AHideNSneakCPPCharacter;
class APickup;

class HIDENSNEAKUNREAL_API PowerUpInventoryItem
{
public:
	PowerUpInventoryItem(AHideNSneakCPPCharacter* InCharacter, APickup* InPickUp);

	AHideNSneakCPPCharacter* Character;

	virtual void ApplyPickUp();

	virtual ~PowerUpInventoryItem();

protected:
	APickup* Pickup;
};
