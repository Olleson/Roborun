// Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamOnlineGameInstance.h"
#include "Net/UnrealNetwork.h"


USteamOnlineGameInstance::USteamOnlineGameInstance() {
	MySessionName = "My Session";
	HidersBaseSpeed = 600;
	SeekersBaseSpeed = 666;
	PlayersBaseJumpHeight = 1000;
}

void USteamOnlineGameInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USteamOnlineGameInstance, HidersBaseSpeed);
	DOREPLIFETIME(USteamOnlineGameInstance, SeekersBaseSpeed);
	DOREPLIFETIME(USteamOnlineGameInstance, PlayersBaseJumpHeight);
	DOREPLIFETIME(USteamOnlineGameInstance, PowerupsEnabled);
	DOREPLIFETIME(USteamOnlineGameInstance, PowerupSpawnRate);
}

void USteamOnlineGameInstance::SetSessionInProgress(bool inProgress)
{
	if (inProgress) {
		SessionInterface->StartSession(MySessionName);
	}
	else
	{
		SessionInterface->EndSession(MySessionName);
	}
}

float USteamOnlineGameInstance::GetPowerupSpawnRate()
{
	return PowerupSpawnRate;
}

void USteamOnlineGameInstance::SetPowerupSpawnRate(float inPowerupSpawnRate)
{
	PowerupSpawnRate = inPowerupSpawnRate;
}
float USteamOnlineGameInstance::GetPowerupsEnabled()
{
	return PowerupsEnabled;
}

void USteamOnlineGameInstance::SetPowerupsEnabled(bool inPowerupsEnabled)
{
	PowerupsEnabled = inPowerupsEnabled;
}
float USteamOnlineGameInstance::GetHidersBaseSpeed()
{
	return HidersBaseSpeed;
}

void USteamOnlineGameInstance::SetHidersBaseSpeed(float inBaseSpeed)
{
	HidersBaseSpeed = inBaseSpeed;
}

float USteamOnlineGameInstance::GetSeekersBaseSpeed()
{
	return SeekersBaseSpeed;
}

void USteamOnlineGameInstance::SetSeekersBaseSpeed(float inBaseSpeed)
{
	SeekersBaseSpeed = inBaseSpeed;
}

float USteamOnlineGameInstance::GetPlayerBaseJumpHeight()
{
	return PlayersBaseJumpHeight;
}

void USteamOnlineGameInstance::SetPlayersBaseJumpHeight(float inJumpHeight)
{
	PlayersBaseJumpHeight = inJumpHeight;
}

void USteamOnlineGameInstance::Init() {
	Super::Init();
	if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get("Steam")) {
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid()) {
			//Bind Delegates Here
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &USteamOnlineGameInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &USteamOnlineGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &USteamOnlineGameInstance::OnJoinSessionComplete);
		}
	}
}
//Add the name of the level you want to spawn in this function (finish it with ?listen)
void USteamOnlineGameInstance::OnCreateSessionComplete(FName ServerName, bool Succeded)
{
	GetWorld()->ServerTravel("/Game/Maps/LobbyHangOutPlace?listen");
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

void USteamOnlineGameInstance::CreateServer(FString ServerName, FString HostName, int MaxPlayerCount)
{
	FOnlineSessionSettings SessionSettings;
	SessionSettings.bAllowJoinInProgress = false;
	SessionSettings.bIsDedicated = false;
	SessionSettings.bIsLANMatch = false;
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUsesPresence = true;
	SessionSettings.NumPublicConnections = MaxPlayerCount;
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
	if (SessionSearch->SearchResults.Num() > ServerIndex && ServerIndex >= 0) {
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

			if(Info.ServerName != "Empty Server Name")
			SteamServerListDelegate.Broadcast(Info);
		}
	}
}
