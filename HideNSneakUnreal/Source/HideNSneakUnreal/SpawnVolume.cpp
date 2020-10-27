// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (HasAuthority()) {
		WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
		//Must #include "Components/BoxComponent.h" for this to work
		RootComponent = WhereToSpawn;

		//Set some base values for the spawn delay range
		MinSpawnDelay = 1.0f;
		MaxSpawnDelay = 4.5f;
	}

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	// Set the timer to start spawning pickups
	SpawnDelay = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	if (WhereToSpawn != NULL) {
		FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
		FVector SpawnExtents = WhereToSpawn->Bounds.BoxExtent;
		return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtents);
	}
	return FVector();
}

void ASpawnVolume::SpawnPickup()
{
	//We only do this if we are the Server and have something to spawn
	if (HasAuthority() && WhatToSpawn != NULL) {
		//Check for valid World
		if (UWorld* const World = GetWorld()) {
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = GetInstigator();

			FVector SpawnLocation = GetRandomPointInVolume();

			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::RandRange(0.0f, 360.0f);
			SpawnRotation.Pitch = FMath::RandRange(0.0f, 360.0f);
			SpawnRotation.Roll = FMath::RandRange(0.0f, 360.0f);

			APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);

			SpawnDelay = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
		}
	}
}

