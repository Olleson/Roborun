//Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#include "InvisibilityPowerUp.h"

AInvisibilityPowerUp::AInvisibilityPowerUp(const FObjectInitializer& OI): Super(OI) {

}

void AInvisibilityPowerUp::ApplyPowerUp(ACharacter* Character) {
	APickup::ApplyPowerUp(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Player->SetMeshVisibility(false);
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AInvisibilityPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AInvisibilityPowerUp::UnApplyPowerUp_Implementation()
{
	//APickup::UnApplyPowerUp();
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->SetMeshVisibility(true);
}