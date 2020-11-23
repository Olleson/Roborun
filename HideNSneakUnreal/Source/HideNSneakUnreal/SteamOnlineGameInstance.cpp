// Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamOnlineGameInstance.h"


USteamOnlineGameInstance::USteamOnlineGameInstance() {
	MySessionName = "My Session";
}

void USteamOnlineGameInstance::Init() {
	Super::Init();
	if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get("Steam")) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Subsystem name: " + Subsystem->GetSubsystemName().ToString()));
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid()) {
			//Bind Delegates Here
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &USteamOnlineGameInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &USteamOnlineGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &USteamOnlineGameInstance::OnJoinSessionComplete);
		}
	}
}
//Add the name of the level you want to spawn in this function (finish it with ?Listen)
void USteamOnlineGameInstance::OnCreateSessionComplete(FName ServerName, bool Succeded)
{
	GetWorld()->ServerTravel("/Game/Maps/Beta_whitebox?listen");
}

void USteamOnlineGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
		FString JoinAddress = "";
		SessionInterface->GetResolvedConnectString(SessionName, JoinAddress);
		if (JoinAddress != "") {
			PlayerController->ClientTravel(JoinAddress, ETravelType::TRAVEL_Absolute);
		}
	}
}

void USteamOnlineGameInstance::CreateServer(FString ServerName, FString HostName)
{
	FOnlineSessionSettings SessionSettings;
	SessionSettings.bAllowJoinInProgress = true;
	SessionSettings.bIsDedicated = false;
	SessionSettings.bIsLANMatch = false;
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUsesPresence = true;
	SessionSettings.NumPublicConnections = 10;
	SessionSettings.Set(FName("SERVER_NAME_KEY"), ServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	SessionSettings.Set(FName("SERVER_HOSTNAME_KEY"), HostName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	SessionInterface->CreateSession(0, MySessionName, SessionSettings);
}

void USteamOnlineGameInstance::FindServers()
{
	SteamSearchingForServerDelegate.Broadcast(true);
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	SessionSearch->bIsLanQuery = false;
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Searching for an online match"));
	SessionSearch->MaxSearchResults = 10000;
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}

void USteamOnlineGameInstance::JoinServer(int32 ServerIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Joining Server..."));
	if (SessionSearch->SearchResults.Num() > ServerIndex && ServerIndex >= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Attempting to connect"));
		FOnlineSessionSearchResult Result = SessionSearch->SearchResults[ServerIndex];
		if (Result.IsValid()) {
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Connecting..."));
			SessionInterface->JoinSession(0, MySessionName, Result);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Error: Server is no longer available"));
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Error: Unexpected Server Array Index"));
	}
}

void USteamOnlineGameInstance::OnFindSessionsComplete(bool Succeded)
{
	SteamSearchingForServerDelegate.Broadcast(false);
	if (Succeded) {
		TArray<FOnlineSessionSearchResult> SearchResults = SessionSearch->SearchResults;

		for (size_t i = 0; i < SearchResults.Num(); i++)
		{
			FOnlineSessionSearchResult Result = SearchResults[i];
			if (!Result.IsValid()) {
				GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Invalid Result"));
				continue;
			}

			FSteamServerInfo Info;
			FString ServerName = "Empty Server Name";
			FString HostName = "Empty Host Name";

			Result.Session.SessionSettings.Get(FName("SERVER_NAME_KEY"), ServerName);
			Result.Session.SessionSettings.Get(FName("SERVER_HOSTNAME_KEY"), HostName);

			Info.ServerName = ServerName;
			Info.MaxPlayers = SearchResults[i].Session.SessionSettings.NumPublicConnections;
			Info.CurrentPlayers = SearchResults[i].Session.NumOpenPublicConnections;
			Info.ServerArrayIndex = i;

			SteamServerListDelegate.Broadcast(Info);
		}
	}
}
