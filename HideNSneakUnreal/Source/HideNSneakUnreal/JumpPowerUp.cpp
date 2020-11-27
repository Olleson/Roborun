// Author: Alexander Aulin

#include "JumpPowerUp.h"

AJumpPowerUp::AJumpPowerUp(const FObjectInitializer& OI) : Super(OI) {
	JumpBoost = 1200.0;
}

void AJumpPowerUp::ApplyPowerUp_Implementation(APawn* Pawn) {
	if (AHideNSneakCPPCharacter* Character = Cast<AHideNSneakCPPCharacter>(Pawn)) {
		Character->GetCharacterMovement()->JumpZVelocity += JumpBoost;
		PlayerQueue.push(Character);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AJumpPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AJumpPowerUp::UnApplyPowerUp_Implementation()
{
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->GetCharacterMovement()->JumpZVelocity = Character->GetBaseJumpHeight();
}