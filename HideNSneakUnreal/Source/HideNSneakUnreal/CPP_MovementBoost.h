//Primary Author: Abdifatah Abdi
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <HideNSneakUnreal/HideNSneakCPPCharacter.h>
#include <Components/StaticMeshComponent.h>
#include <GameFrameWork/Actor.h>
#include <Components/BoxComponent.h>
#include "CPP_MovementBoost.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API ACPP_MovementBoost : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_MovementBoost();

	UPROPERTY(EditAnywhere)
		float Speedincrease = 800.0f;

	UPROPERTY(EditAnywhere)
		float RespawnTime = 60.0f;

	UPROPERTY(EditAnywhere)
		float Duration = 3.0f;
	UPROPERTY(EditAnywhere)
		float OriginalSpeed = 600.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//if true then the players powerup is activated
	bool bPowerActive = true;

	//Handles the time the power is active
	FTimerHandle PowerTimerHandle;

	//Handles the respawn time of the power
	FTimerHandle PowerRespawnTimerHandle;

	UFUNCTION()
		void ResetPowers();

	UFUNCTION()
		void RespawnPowerup();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AHideNSneakCPPCharacter* Character;

	//CollisionBox
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* CollisionBox;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};