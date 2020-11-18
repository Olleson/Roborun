// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpInventoryItem.h"

PowerUpInventoryItem::PowerUpInventoryItem(AHideNSneakCPPCharacter* InCharacter, APickup* InPickUp): Character(InCharacter), Pickup(InPickUp)
{
}

void PowerUpInventoryItem::ApplyPickUp()
{
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Inventory item activates power up"));
	Pickup->ClientApplyPowerUp(Character);
}

PowerUpInventoryItem::~PowerUpInventoryItem()
{
	Character = NULL;
	Pickup = NULL;
}
