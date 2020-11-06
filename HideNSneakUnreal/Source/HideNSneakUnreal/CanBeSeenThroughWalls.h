//Author: Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CanBeSeenThroughWalls.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HIDENSNEAKUNREAL_API UCanBeSeenThroughWalls : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCanBeSeenThroughWalls();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
};