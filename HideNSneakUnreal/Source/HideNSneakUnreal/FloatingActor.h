// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class QUICKSTART_API AFloatingActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFloatingActor();

    UPROPERTY(VisibleAnywhere)
        UStaticMeshComponent* VisualMesh;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;