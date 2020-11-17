//Primary Author: Abdifatah Abdi

#pragma once

#include "CoreMinimal.h"
#include "CPP_Character.h"
#include <HideNSneakUnreal/HideNSneakCPPCharacter.h>
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>
#include <GameFrameWork/Actor.h>
#include <Components/BoxComponent.h>
#include <DrawDebugHelpers.h>

#include "CPP_Powerup.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API ACPP_Powerup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's propertie
	ACPP_Powerup();

	UPROPERTY(EditAnywhere)
		float duration = 3.0f;
	UPROPERTY(EditAnywhere)
		float RespawnTime = 60.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//if true then the players powerup is activated
	bool bPowerActive = true;

	//Handles the time the power is active
	FTimerHandle PowerTimerHandle;

	FTimerHandle PowerRespawnTimerHandle;
	UFUNCTION()
		void ResetPowers();

	UFUNCTION()
		void RespawnPowerup();

public:
	// Called every frame
	AHideNSneakCPPCharacter* Character;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* CollisionBox;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};