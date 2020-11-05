// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Character.h"
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

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	ACPP_Character* Character;


	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* CollisionBox;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
};
