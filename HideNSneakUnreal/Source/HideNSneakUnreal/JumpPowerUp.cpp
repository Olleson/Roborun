// Author: Alexander Aulin

#include "JumpPowerUp.h"

AJumpPowerUp::AJumpPowerUp(const FObjectInitializer& OI) : Super(OI) {
	JumpBoost = 1200.0;
}

void AJumpPowerUp::ApplyPowerUp_Implementation(ACharacter* Character) {
	APickup::ApplyPowerUp_Implementation(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Character->GetCharacterMovement()->JumpZVelocity += JumpBoost;
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AJumpPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AJumpPowerUp::UnApplyPowerUp_Implementation()
{
	APickup::UnApplyPowerUp_Implementation();
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->GetCharacterMovement()->JumpZVelocity = Character->GetBaseJumpHeight();
}