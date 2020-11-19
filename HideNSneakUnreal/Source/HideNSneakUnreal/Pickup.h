//Author: Abdi Abdifatah
//Co Author: Oskar Johansson

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "HideNSneakCPPCharacter.h"
#include "Pickup.generated.h"

class AHideNSneakCPPCharacter;

UCLASS()
class HIDENSNEAKUNREAL_API APickup : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	/** Set default values via Constructor */
	APickup();

	/** Required Network Scaffolding */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintPure, Category = "Pickup")
		// Returns wether the pickup is active or not
		bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		// Lets other classes safely change the pickup's activation state
		void SetActive(bool NewPickupState);

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		// Returns the pickup icon
		UTexture2D* GetPickupIcon();

	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
		// Function to call when the pickup is collected
		void WasCollected();
	virtual void WasCollected_Implementation();

	UFUNCTION(BlueprintAuthorityOnly, Category = "Pickup")
		// Server side handling of being picked up
		virtual void PickedUpBy(APawn* Pawn);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Pickup")
		// Applies the powerup effect to the received character and adds them to the queue
		void ApplyPowerUp(APawn* Pawn);
	virtual void ApplyPowerUp_Implementation(APawn* Pawn) {}

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "Pickup")
		// Requests the server to replicate the power up on all clients
		void ClientApplyPowerUp(APawn* Pawn);
	void ClientApplyPowerUp_Implementation(APawn* Pawn);

	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
		// Deactivates the powerup effect on the next player in the queue
		void UnApplyPowerUp();
	virtual void UnApplyPowerUp_Implementation() {}

protected:
	/** True when the pickup can be used, false when deactivated */
	UPROPERTY(ReplicatedUsing = OnRep_IsActive)
		bool bIsActive;

	/** This is called whenever bIsActive is updated */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		virtual void OnRep_IsActive();

	// The pawn who picked up the pickup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
		APawn* PickupInstigator;

	// The duration, in seconds, the pickup is applied when activated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		float PowerUpDuration;

	// Check if this pickup should respawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		bool Respawns;

	// The time, in seconds, it takes for the pickup to respawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		float RespawnDelay;

	// The icon that is shown when a player picks up the pickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		UTexture2D* PickupIcon;

	UFUNCTION(BlueprintCallable, Category = "Pickup", meta = (BlueprintProtected = "true"))
		// Respawns the pickup
		virtual void RespawnPickup();

	// Queue used to keep track of which player's poweup effect should be deactivated next
	std::queue<AHideNSneakCPPCharacter*> PlayerQueue;

private:
	UFUNCTION(NetMulticast, Unreliable)
		// Client side handling of being picked up
		void ClientOnPickedUpBy(APawn* Pawn);
	void ClientOnPickedUpBy_Implementation(APawn* Pawn);

	// Timer handle used to time respawning
	FTimerHandle RespawnTimer;
};