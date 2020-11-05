// Fill out your copyright notice in the Description page of Project Settings.


#include "HideNSneakGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AHideNSneakGameModeBase::AHideNSneakGameModeBase()
{
    CurrentRoundIndex = 0;
}

void AHideNSneakGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    Controllers = GetWorld()->GetFirstPlayerController();
    

}

void AHideNSneakGameModeBase::CheckRound() 
{

}

void AHideNSneakGameModeBase::AssignRoles()
{
    
    
}

void AHideNSneakGameModeBase::EndGame()
{
    
}

void AHideNSneakGameModeBase::LoadNextRound()
{
    
}