//Author: Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HideNSneakTextChatStateCpp.generated.h"
#include "HideNSneakHUDCPP.h"

/**
 * 
 */
UCLASS()
class HIDENSNEAKUNREAL_API AHideNSneakTextChatStateCpp : public APlayerState
{
	GENERATED_BODY()
	
public:

	AHideNSneakTextChatStateCpp();

	UFUNCTION(Server, Reliable, WithValidation) // for player to player rpc you need to first call the message on the server
		virtual void UserChatRPC(const FSChatMsg& newmessage); // first rpc for the server
	UFUNCTION(NetMulticast, Reliable, WithValidation) // then the server calls the function with a multicast that executes on all clients and the server
		virtual void UserChat(const FSChatMsg& newmessage); // second rpc for all the clients
};
