// Author: Alexander Aulin

#include "JumpPowerUp.h"

AJumpPowerUp::AJumpPowerUp(const FObjectInitializer& OI) : Super(OI) {
	JumpBoost = 1200.0;
}

void AJumpPowerUp::ApplyPowerUp(ACharacter* Character) {
	APickup::ApplyPowerUp(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Character->GetCharacterMovement()->JumpZVelocity += JumpBoost;
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AJumpPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AJumpPowerUp::UnApplyPowerUp()
{
	APickup::UnApplyPowerUp();
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->GetCharacterMovement()->JumpZVelocity = Character->GetBaseJumpHeight();
}