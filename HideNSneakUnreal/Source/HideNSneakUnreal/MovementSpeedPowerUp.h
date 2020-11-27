// Author: Alexander Aulin
//Co-author: Abdi Abdifatah

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "HideNSneakCPPCharacter.h"
#include "MovementSpeedPowerUp.generated.h"

class AHideNSneakCPPCharacter;

UCLASS()
class HIDENSNEAKUNREAL_API AMovementSpeedPowerUp : public APickup
{
	GENERATED_BODY()

public:
	AMovementSpeedPowerUp(const FObjectInitializer& OI);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (AllowPrivateAcces = "true"))
		float MovementSpeedBoost;

	void ApplyPowerUp_Implementation(APawn* Pawn) override;

	void UnApplyPowerUp_Implementation() override;
};