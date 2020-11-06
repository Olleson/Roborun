//Author: Olle Frid

#include "CanBeSeenThroughWalls.h"

UCanBeSeenThroughWalls::UCanBeSeenThroughWalls() {
	PrimaryComponentTick.bCanEverTick = true;

}

void UCanBeSeenThroughWalls::BeginPlay() {
	Super::BeginPlay();
	
}

void UCanBeSeenThroughWalls::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}