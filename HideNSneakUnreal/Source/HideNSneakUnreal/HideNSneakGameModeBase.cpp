// Fill out your copyright notice in the Description page of Project Settings.

#include "HideNSneakGameModeBase.h"
#include "HideNSneakUnreal.h"

AHideNSneakGameModeBase::AHideNSneakGameModeBase()
{
	/* use this is you wish to extend the c++ into a bp and assign the bp to the class
	static ConstructorHelpers::FClassFinder<AMyHUD> hudclassobj(TEXT("Blueprint'/MyHUD.MyHUD_C'"));
	if (hudclassobj.Class != NULL)
		HUDClass = hudclassobj.Class;

	static ConstructorHelpers::FClassFinder<AMyPlayerState> psclassobj(TEXT("Blueprint'/MyPlayerState.MyPlayerState_C'"));
	if (psclassobj.Class != NULL)
		PlayerStateClass = psclassobj.Class;
	*/

	// Set default values
	HidersBaseSpeed = 600.0;
	SeekersBaseSpeed = 666.0;
	PlayersBaseJumpHeight = 1000;
}

float AHideNSneakGameModeBase::GetHidersBaseSpeed()
{
	return HidersBaseSpeed;
}

 void AHideNSneakGameModeBase::SetHidersBaseSpeed(float inBaseSpeed)
{
	 HidersBaseSpeed = inBaseSpeed;
}

 float AHideNSneakGameModeBase::GetSeekersBaseSpeed()
 {
	 return SeekersBaseSpeed;
 }

 void AHideNSneakGameModeBase::SetSeekersBaseSpeed(float inBaseSpeed)
 {
	 SeekersBaseSpeed = inBaseSpeed;
 }

 float AHideNSneakGameModeBase::GetPlayerBaseJumpHeight()
 {
	 return PlayersBaseJumpHeight;
 }

 void AHideNSneakGameModeBase::SetPlayersBaseJumpHeight(float inJumpHeight)
 {
	 PlayersBaseJumpHeight = inJumpHeight;
 }
