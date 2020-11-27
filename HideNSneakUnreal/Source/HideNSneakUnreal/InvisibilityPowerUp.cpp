//Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#include "InvisibilityPowerUp.h"

AInvisibilityPowerUp::AInvisibilityPowerUp(const FObjectInitializer& OI): Super(OI) {

}

void AInvisibilityPowerUp::ApplyPowerUp_Implementation(APawn* Pawn) {
	if (AHideNSneakCPPCharacter* Character = Cast<AHideNSneakCPPCharacter>(Pawn)) {
		Character->SetActorHiddenInGame(true);
		PlayerQueue.push(Character);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AInvisibilityPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void AInvisibilityPowerUp::UnApplyPowerUp_Implementation()
{
	AHideNSneakCPPCharacter* Character = PlayerQueue.front();
	PlayerQueue.pop();
	Character->SetActorHiddenInGame(false);
}