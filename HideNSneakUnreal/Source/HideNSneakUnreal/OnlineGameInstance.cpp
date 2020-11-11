//Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"

UOnlineGameInstance::UOnlineGameInstance() {
	MySessionName = "My Session";
}

void UOnlineGameInstance::Init()
{
	Super::Init();
	if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get()) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Subsystem name: " + Subsystem->GetSubsystemName().ToString()));
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
	GetWorld()->ServerTravel("/Game/Maps/Alpha_playable_whitebox?listen");
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

			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, ServerName + " has been found");
			ServerListDelegate.Broadcast(Info);
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
	SessionSettings.bIsLANMatch = false;
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Hosting an online match"));
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
	SessionSearch->bIsLanQuery = false;
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Searching for an online match"));
	SessionSearch->MaxSearchResults = 10000;
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}

void UOnlineGameInstance::JoinServer(int32 ServerIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Joining Server..."));
	if (SessionSearch->SearchResults.Num() > ServerIndex && ServerIndex >= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Attempting to connect"));
		FOnlineSessionSearchResult Result = SessionSearch->SearchResults[ServerIndex];
		if (Result.IsValid()) {
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString("Connecting..."));
			SessionInterface->JoinSession(0, MySessionName, Result);
		}
	}
}
