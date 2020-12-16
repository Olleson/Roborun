// Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SteamOnlineGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FSteamServerInfo {

	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
		FString ServerName;

	UPROPERTY(BlueprintReadOnly)
		FString PlayerCountStr;

	UPROPERTY(BlueprintReadOnly)
		int32 CurrentPlayers;

	UPROPERTY(BlueprintReadOnly)
		int32 MaxPlayers;

	UPROPERTY(BlueprintReadOnly)
		int32 ServerArrayIndex;

	void SetPlayerCount() {
		PlayerCountStr = FString(FString::FromInt(CurrentPlayers) + "/" + FString::FromInt(MaxPlayers));
	}
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSteamServerDelegate, FSteamServerInfo, SteamServerListDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSteamServerSearchingDelegate, bool, SteamSearchingForServerDelegate);
/**
 *
 */
UCLASS()
class HIDENSNEAKUNREAL_API USteamOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	USteamOnlineGameInstance();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool IsNotInOnlineMode;

	UFUNCTION(BlueprintCallable, Category = "Session Settings")
		void SetAllowJoinInProgress(bool Permission);

protected:

	virtual void Init() override;

	FName MySessionName;

	UPROPERTY(BlueprintAssignable)
		FSteamServerDelegate SteamServerListDelegate;

	UPROPERTY(BlueprintAssignable)
		FSteamServerSearchingDelegate SteamSearchingForServerDelegate;

	// Delegate for finalizing session creation
	virtual void OnCreateSessionComplete(FName ServerName, bool Succeded);

	// Delegate for finalizing finindg sessions
	virtual void OnFindSessionsComplete(bool Succeded);

	// Delegate for finalizing joining a session
	virtual void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	IOnlineSessionPtr SessionInterface;

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	// Creates a session and sets session settings
	UFUNCTION(BlueprintCallable, Category = "OnlineLobby")
		void CreateServer(FString ServerName, FString HostName, int MaxPlayerCount);

	// Finds available sessions
	UFUNCTION(BlueprintCallable, Category = "OnlineLobby")
		void FindServers();

	// Joins a session
	UFUNCTION(BlueprintCallable, Category = "OnlineLobby")
		void JoinServer(int32 ServerIndex);
};
