// Fill out your copyright notice in the Description page of Project Settings.


#include "batman.h"

// Sets default values
Abatman::Abatman()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Abatman::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Abatman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Abatman::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

