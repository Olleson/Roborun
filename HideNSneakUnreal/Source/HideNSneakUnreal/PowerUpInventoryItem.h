// Author: Alexander Aulin

#pragma once

#include "CoreMinimal.h"
#include "HideNSneakCPPCharacter.h"
#include "Pickup.h"

/**
 * This class is used as a proxy to avoid circular dependancy between APickup and AHideNSNeakCPPCharacter
 */
class AHideNSneakCPPCharacter; //Forward declaration
class APickup; //Forward declaration

class HIDENSNEAKUNREAL_API PowerUpInventoryItem
{
public:
	PowerUpInventoryItem(AHideNSneakCPPCharacter* InCharacter, APickup* InPickUp);

	AHideNSneakCPPCharacter* Character;

	virtual void ApplyPickUp();

	UTexture2D* GetPickUpIcon();

	virtual ~PowerUpInventoryItem();

protected:
	APickup* Pickup;
};
