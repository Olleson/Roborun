// Author: Alexander Aulin

#include "PowerUpInventoryItem.h"

PowerUpInventoryItem::PowerUpInventoryItem(AHideNSneakCPPCharacter* InCharacter, APickup* InPickUp) : Character(InCharacter), Pickup(InPickUp) { }

void PowerUpInventoryItem::ApplyPickUp()
{
	Pickup->ApplyPowerUp(Character);
}

UTexture2D* PowerUpInventoryItem::GetPickUpIcon()
{
	return Pickup->GetPickupIcon();
}

PowerUpInventoryItem::~PowerUpInventoryItem()
{
	// Nullify pointers so it doesn't try to delete the character and pickup upon being destroyed
	Character = nullptr;
	Pickup = nullptr;
}