// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovingPlatform.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HIDENSNEAKUNREAL_API UMovingPlatform : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovingPlatform();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		virtual float setSpeed(float traveltime, float distance);

	UFUNCTION(BlueprintCallable)
		virtual void SetMovementVector(FVector CurrentLocation, FVector TargetLocation, float MovementSpeed , FVector &MovementVector);

	UFUNCTION(BlueprintCallable)
		virtual bool MovePlatform(FVector targetPosition, FVector CurrentPosition, FVector EndPosition, FVector StartPosition, float MovementSpeed, FVector &TargetPositionOut, FVector &MovementVectorOut);
};
