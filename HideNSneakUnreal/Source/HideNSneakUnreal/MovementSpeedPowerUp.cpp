// Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#include "MovementSpeedPowerUp.h"

AMovementSpeedPowerUp::AMovementSpeedPowerUp(const FObjectInitializer& OI) : Super(OI) {
	// Set base value for the speed boost
	MovementSpeedBoost = 100.0;
}


void AMovementSpeedPowerUp::ApplyPowerUp_Implementation(APawn* Pawn)
{
	APickup::ApplyPowerUp_Implementation(Pawn);
	if (AHideNSneakCPPCharacter* Character = Cast<AHideNSneakCPPCharacter>(Pawn)) {
		Character->GetCharacterMovement()->MaxWalkSpeed += MovementSpeedBoost;
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Speed boost applied"));
		PlayerQueue.push(Character);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AMovementSpeedPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AMovementSpeedPowerUp::UnApplyPowerUp_Implementation()
{
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->GetCharacterMovement()->MaxWalkSpeed = Character->GetBaseSpeed();
}