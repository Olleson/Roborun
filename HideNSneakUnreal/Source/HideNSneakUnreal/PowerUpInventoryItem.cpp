// Author: Alexander Aulin


#include "PowerUpInventoryItem.h"

PowerUpInventoryItem::PowerUpInventoryItem(AHideNSneakCPPCharacter* InCharacter, APickup* InPickUp): Character(InCharacter), Pickup(InPickUp)
{
}

void PowerUpInventoryItem::ApplyPickUp()
{
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Inventory item activates power up"));
	Pickup->ClientApplyPowerUp(Character);
}

UTexture2D* PowerUpInventoryItem::GetPickUpIcon()
{
	return Pickup->GetPickupIcon();
}

PowerUpInventoryItem::~PowerUpInventoryItem()
{
	// Nullify pointers so it doesn't try to delete the character and pickup upon being destroyed
	Character = NULL;
	Pickup = NULL;
}
