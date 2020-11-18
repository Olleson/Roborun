// Fill out your copyright notice in the Description page of Project Settings.


#include "InvisibilityPowerUp.h"

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
