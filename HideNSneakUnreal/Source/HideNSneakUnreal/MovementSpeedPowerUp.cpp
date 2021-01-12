// Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#include "MovementSpeedPowerUp.h"

AMovementSpeedPowerUp::AMovementSpeedPowerUp(const FObjectInitializer& OI) : Super(OI) {
	// Set base value for the speed boost
	MovementSpeedBoost = 100.0;
}


void AMovementSpeedPowerUp::ApplyPowerUp(ACharacter* Character)
{
	APickup::ApplyPowerUp(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Player->GetCharacterMovement()->MaxWalkSpeed += MovementSpeedBoost;
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AMovementSpeedPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AMovementSpeedPowerUp::UnApplyPowerUp_Implementation()
{
	//APickup::UnApplyPowerUp();
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->GetCharacterMovement()->MaxWalkSpeed = Character->GetBaseSpeed();
}