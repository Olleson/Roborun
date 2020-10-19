// Fill out your copyright notice in the Description page of Project Settings.


#include "OllesPlayerCharacter.h"

// Sets default values
AOllesPlayerCharacter::AOllesPlayerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOllesPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOllesPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOllesPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

