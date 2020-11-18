//Author: Alexande Aulin
//Co-author: Abdi Abdifatah

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "InvisibilityPowerUp.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API AInvisibilityPowerUp : public APickup
{
	GENERATED_BODY()
	
public:
	void ApplyPowerUp_Implementation(APawn* Pawn) override;

	void UnApplyPowerUp_Implementation() override;
};