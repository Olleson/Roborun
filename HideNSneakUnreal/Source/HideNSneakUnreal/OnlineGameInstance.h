//Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "OnlineGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FServerInfo {

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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerDelegate, FServerInfo, ServerListDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerSearchingDelegate, bool, SearchingForServerDelegate);
/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UOnlineGameInstance();

protected:
	virtual void Init() override;

	FName MySessionName;

	UPROPERTY(BlueprintAssignable)
		FServerDelegate ServerListDel;

	UPROPERTY(BlueprintAssignable)
		FServerSearchingDelegate SearchingForServerDelegate;

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
		void CreateServer(FString ServerName, FString HostName);

	// Finds available sessions
	UFUNCTION(BlueprintCallable, Category = "OnlineLobby")
		void FindServers();

	// Joins a session
	UFUNCTION(BlueprintCallable, Category = "OnlineLobby")
		void JoinServer(int32 ServerIndex);
};
