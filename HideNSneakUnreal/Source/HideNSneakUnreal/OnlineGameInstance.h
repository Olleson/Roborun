//Author: Alexander Aulin
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Engine/GameInstance.h"
#include "OnlineGameInstance.generated.h"

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
		void CreateServer();

	// Finds available sessions
	UFUNCTION(BlueprintCallable, Category = "OnlineLobby")
		void JoinServer();
};
