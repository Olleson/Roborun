//Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#include "InvisibilityPowerUp.h"

AInvisibilityPowerUp::AInvisibilityPowerUp(const FObjectInitializer& OI): Super(OI) {

}

void AInvisibilityPowerUp::ApplyPowerUp_Implementation(ACharacter* Character) {
	APickup::ApplyPowerUp_Implementation(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Character->SetActorHiddenInGame(true);
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AInvisibilityPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AInvisibilityPowerUp::UnApplyPowerUp_Implementation()
{
	APickup::UnApplyPowerUp_Implementation();
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->SetActorHiddenInGame(false);
}