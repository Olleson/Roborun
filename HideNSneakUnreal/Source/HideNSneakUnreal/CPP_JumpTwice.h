// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Character.h"
#include <Components/StaticMeshComponent.h>
#include <GameFrameWork/Actor.h>
#include <Components/BoxComponent.h>
#include <DrawDebugHelpers.h>
#include "CPP_JumpTwice.generated.h"


UCLASS()
class HIDENSNEAKUNREAL_API ACPP_JumpTwice : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_JumpTwice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//if true then the players powerup is activated
	bool bPowerActive = true;

	//Handles the time the power is active
	FTimerHandle PowerTimerHandle;

	void ResetPowers();




public:	
	// Called every frame
	ACPP_Character* Character;


	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* CollisionBox;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



};
