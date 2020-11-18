// Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementSpeedPowerUp.h"

AMovementSpeedPowerUp::AMovementSpeedPowerUp() {
	// Set base value for the speed boost
	MovementSpeedBoost = 100.0;
}


void AMovementSpeedPowerUp::ApplyPowerUp_Implementation(APawn* Pawn)
{
	APickup::ApplyPowerUp_Implementation(Pawn);
	if (AHideNSneakCPPCharacter* Character = Cast<AHideNSneakCPPCharacter>(Pawn)) {
		Character->GetCharacterMovement()->MaxWalkSpeed += MovementSpeedBoost;
		PlayerQueue.push(Character);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AMovementSpeedPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AMovementSpeedPowerUp::UnApplyPowerUp_Implementation()
{
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	Character->GetCharacterMovement()->MaxWalkSpeed = Character->GetBaseSpeed();
}
