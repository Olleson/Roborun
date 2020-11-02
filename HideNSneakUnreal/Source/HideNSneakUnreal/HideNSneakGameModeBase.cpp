// Fill out your copyright notice in the Description page of Project Settings.

#include "HideNSneakGameModeBase.h"
#include "HideNSneakUnreal.h"
#include "HideNSneakHUDCPP.h"
#include "HideNSneakTextChatStateCPP.h"

AHideNSneakGameModeBase::AHideNSneakGameModeBase()
{
	// assign our custom classes above their parents
	HUDClass = AHideNSneakHUDCPP::StaticClass();
	PlayerStateClass = AHideNSneakTextChatStateCpp::StaticClass();

	/* use this is you wish to extend the c++ into a bp and assign the bp to the class
	static ConstructorHelpers::FClassFinder<AMyHUD> hudclassobj(TEXT("Blueprint'/MyHUD.MyHUD_C'"));
	if (hudclassobj.Class != NULL)
		HUDClass = hudclassobj.Class;

	static ConstructorHelpers::FClassFinder<AMyPlayerState> psclassobj(TEXT("Blueprint'/MyPlayerState.MyPlayerState_C'"));
	if (psclassobj.Class != NULL)
		PlayerStateClass = psclassobj.Class;
	*/
}