//Author: Olle Frid

#include "HideNSneakTextChatStateCpp.h"
#include "HideNSneakUnreal.h"
#include "HideNSneakHUDCPP.h"
#include "HideNSneakTextChatWidget.h"

AHideNSneakTextChatStateCpp::AHideNSneakTextChatStateCpp()
{

}

bool AHideNSneakTextChatStateCpp::UserChatRPC_Validate(const FSChatMsg& newmessage)
{
	return true;
}
void AHideNSneakTextChatStateCpp::UserChatRPC_Implementation(const FSChatMsg& newmessage)
{
	UserChat(newmessage);
}
bool AHideNSneakTextChatStateCpp::UserChat_Validate(const FSChatMsg& newmessage)
{
	return true;
}
void AHideNSneakTextChatStateCpp::UserChat_Implementation(const FSChatMsg& newmessage)
{
	APlayerController* MyCon;
	AHideNSneakHUDCPP* MyHud;

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator) // find all controllers
	{
		MyCon = Cast<APlayerController>(*Iterator);
		if (MyCon)
		{
			MyHud = Cast<AHideNSneakHUDCPP>(MyCon->GetHUD());
			if (MyHud && MyHud->MyUIWidget.IsValid())
				MyHud->MyUIWidget->AddMessage(newmessage); // place the chat message on this player controller
		}
	}
}