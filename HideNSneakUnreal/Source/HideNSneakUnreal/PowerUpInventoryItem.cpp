// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpInventoryItem.h"

PowerUpInventoryItem::PowerUpInventoryItem(AHideNSneakCPPCharacter* InCharacter, APickup* InPickUp): Character(InCharacter), Pickup(InPickUp)
{
}

void PowerUpInventoryItem::ApplyPickUp()
{
	Pickup->ApplyPowerUp(Character);
}

PowerUpInventoryItem::~PowerUpInventoryItem()
{
	Character = NULL;
	Pickup = NULL;
}
