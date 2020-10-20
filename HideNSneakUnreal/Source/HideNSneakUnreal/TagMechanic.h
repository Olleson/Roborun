//Author: Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class HIDENSNEAKUNREAL_API TagMechanic : public AActor
{
public:
    // Sets default values for this actor's properties
    TagMechanic();

    UPROPERTY(VisibleAnywhere)
        float* a;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
};