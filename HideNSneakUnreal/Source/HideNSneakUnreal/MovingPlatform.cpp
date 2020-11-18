//Author: Oskar Johansson
// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values for this component's properties
UMovingPlatform::UMovingPlatform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ThisActor = this->GetOwner();
	// ...
}


// Called when the game starts
void UMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovingPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UMovingPlatform::setSpeed(float traveltime, float distance)
{	
	return distance / traveltime;
}

void UMovingPlatform::SetMovementVector(FVector CurrentLocation, FVector TargetLocation, float MovementSpeed , FVector& MovementVector)
{
	MovementVector = (TargetLocation - CurrentLocation).GetSafeNormal();
}

bool UMovingPlatform::MovePlatform(FVector targetPosition, FVector CurrentPosition, FVector EndPosition, FVector StartPosition, float MovementSpeed, FVector& TargetPositionOut, FVector& MovementVectorOut){
	if ((targetPosition - CurrentPosition).Size() <= MovementSpeed * FApp::GetDeltaTime()) {
		if (targetPosition == StartPosition){
			TargetPositionOut = EndPosition;
			MovementVectorOut = (EndPosition - StartPosition).GetSafeNormal();
		}
		else {
			TargetPositionOut = StartPosition;
			MovementVectorOut = (StartPosition - EndPosition).GetSafeNormal();
		}
		return true;
	}
	else {
		return false;
	}
}

void UMovingPlatform::SetTickAndTarget(const FVector TargetPosition)
{
	if (!this->GetOwner()->IsActorTickEnabled()) {
		this->GetOwner()->SetActorTickEnabled(true);
	}
}
