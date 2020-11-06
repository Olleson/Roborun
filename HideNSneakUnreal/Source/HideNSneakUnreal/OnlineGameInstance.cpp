//Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

UOnlineGameInstance::UOnlineGameInstance() {

}

void UOnlineGameInstance::Init()
{
	if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get()) {
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid()) {
			//Bind Delegates Here
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnJoinSessionComplete);
		}
	}
}

void UOnlineGameInstance::OnCreateSessionComplete(FName ServerName, bool Succeded)
{
	GetWorld()->ServerTravel("/Game/Maps/Real_WhiteBox?listen");
}

void UOnlineGameInstance::OnFindSessionsComplete(bool Succeded)
{
	if (Succeded) {
		TArray<FOnlineSessionSearchResult> SearchResults = SessionSearch->SearchResults;

		if (SearchResults.Num()) {
			SessionInterface->JoinSession(0, "MySession", SearchResults[0]);
		}
	}
}

void UOnlineGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
		FString JoinAddress = "";
		SessionInterface->GetResolvedConnectString(SessionName, JoinAddress);
		if (JoinAddress != "") {
			PlayerController->ClientTravel(JoinAddress, ETravelType::TRAVEL_Absolute);
		}
	}
}

void UOnlineGameInstance::CreateServer()
{
	FOnlineSessionSettings SessionSettings;
	SessionSettings.bAllowJoinInProgress = true;
	SessionSettings.bIsDedicated = false;
	if (IOnlineSubsystem::Get()->GetSubsystemName() != "NULL") {
		SessionSettings.bIsLANMatch = false;
	}
	else {
		SessionSettings.bIsLANMatch = true;
	}
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUsesPresence = true;
	SessionSettings.NumPublicConnections = 10;

	SessionInterface->CreateSession(0, FName("My Session"), SessionSettings);

}

void UOnlineGameInstance::JoinServer()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (IOnlineSubsystem::Get()->GetSubsystemName() != "NULL") {
		SessionSearch->bIsLanQuery = false;
	}
	else
	{
		SessionSearch->bIsLanQuery = true;
	}
	SessionSearch->MaxSearchResults = 10000;
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}
