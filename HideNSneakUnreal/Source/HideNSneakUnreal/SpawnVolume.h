// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns the spawn volume's box component */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() { return WhereToSpawn; }

	/** Finds (and returns) a random point in the box component */
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();

protected:
	/* This is the pickup to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class APickup> WhatToSpawn;

	// Acces to the timer for reccuring spawning
	FTimerHandle SpawnTimer;

	// Maximum time in seconds between spawnings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float MaxSpawnDelay;

	// Minimum time in seconds between spawnings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float MinSpawnDelay;

private:
	/** This is  the area where pickups will be created */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", Meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	/* Handles the spawning of a new pickup */
	void SpawnPickup();

	// Actual time in seconds before the next pickup spawning
	float SpawnDelay;

};
