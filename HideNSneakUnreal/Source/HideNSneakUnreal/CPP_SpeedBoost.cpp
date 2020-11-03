// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_SpeedBoost.h"

// Sets default values
ACPP_SpeedBoost::ACPP_SpeedBoost()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_SpeedBoost::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_SpeedBoost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_SpeedBoost::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

