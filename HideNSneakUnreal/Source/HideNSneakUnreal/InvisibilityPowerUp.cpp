//Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#include "InvisibilityPowerUp.h"

AInvisibilityPowerUp::AInvisibilityPowerUp(const FObjectInitializer& OI): Super(OI) {

}

void AInvisibilityPowerUp::ApplyPowerUp(ACharacter* Character) {
	APickup::ApplyPowerUp(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Character->SetActorHiddenInGame(true);
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AInvisibilityPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AInvisibilityPowerUp::UnApplyPowerUp()
{
	APickup::UnApplyPowerUp();
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->SetActorHiddenInGame(false);
}