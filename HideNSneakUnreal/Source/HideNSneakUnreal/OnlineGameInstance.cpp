//Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"

UOnlineGameInstance::UOnlineGameInstance() {
	MySessionName = "My Session";
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
	SearchingForServerDelegate.Broadcast(false);
	if (Succeded) {
		TArray<FOnlineSessionSearchResult> SearchResults = SessionSearch->SearchResults;

		for (size_t i = 0; i < SearchResults.Num(); i++)
		{
			FOnlineSessionSearchResult Result = SearchResults[i];
			if (!Result.IsValid()) {
				continue;
			}

			FServerInfo Info;
			FString ServerName = "Empty Server Name";
			FString HostName = "Empty Host Name";

			Result.Session.SessionSettings.Get(FName("SERVER_NAME_KEY"), ServerName);
			Result.Session.SessionSettings.Get(FName("SERVER_HOSTNAME_KEY"), HostName);

			Info.ServerName = ServerName;
			Info.MaxPlayers = SearchResults[i].Session.SessionSettings.NumPublicConnections;
			Info.CurrentPlayers = SearchResults[i].Session.NumOpenPublicConnections;
			Info.ServerArrayIndex = i;

			ServerListDel.Broadcast(Info);
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

void UOnlineGameInstance::CreateServer(FString ServerName, FString HostName)
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
	SessionSettings.Set(FName("SERVER_NAME_KEY"), ServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	SessionSettings.Set(FName("SERVER_HOSTNAME_KEY"), HostName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	SessionInterface->CreateSession(0, MySessionName, SessionSettings);

}

void UOnlineGameInstance::FindServers()
{
	SearchingForServerDelegate.Broadcast(true);
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

void UOnlineGameInstance::JoinServer(int32 ServerIndex)
{
	if (SessionSearch->SearchResults.Num() < ServerIndex && ServerIndex > 0) {
		FOnlineSessionSearchResult Result = SessionSearch->SearchResults[ServerIndex];
		if (Result.IsValid()) {
			SessionInterface->JoinSession(0, MySessionName, Result);
		}
	}
}
