// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "moveableBox.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HIDENSNEAKUNREAL_API UmoveableBox : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		AActor* SelfActor;
	UPROPERTY(EditAnywhere)
		FVector StartPosition;
	UPROPERTY(EditAnywhere)
		FVector EndPosition;
	UPROPERTY(EditAnywhere)
		FVector movementvecktor;
	UPROPERTY(EditAnywhere)
		float MovementDistance;
	UPROPERTY(EditAnywhere)
		float MovementSpeed;
	UPROPERTY(EditAnywhere)
		FVector TargetPosition;



		

public:	
	// Sets default values for this component's properties
	UmoveableBox();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
