//Author: Abdi Abdifatah
//Co Author: Oskar Johansson
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "HideNSneakCPPCharacter.h"
#include "Pickup.generated.h"

/**
 * 
 */
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

	/** Returns wether the pickup is active or not */
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();

	/** Lets other classes safely change the pickup's activation state */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

	// Function to call when the pickup is collected
	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
		void WasCollected();
	virtual void WasCollected_Implementation();

	// Server side handling of being picked up
	UFUNCTION(BlueprintAuthorityOnly, Category = "Pickup")
		virtual void PickedUpBy(APawn* Pawn);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Pickup")
		void ApplyPowerUp(APawn* Pawn);
	virtual void ApplyPowerUp_Implementation(APawn* Pawn){}

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "Pickup")
		void ClientApplyPowerUp(APawn* Pawn);
		void ClientApplyPowerUp_Implementation(APawn* Pawn);

	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		float PowerUpDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		bool Respawns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		float RespawnDelay;

	UFUNCTION(BlueprintCallable, Category = "Pickup", meta = (BlueprintProtected = "true"))
		virtual void RespawnPickup();

	std::queue<AHideNSneakCPPCharacter*> PlayerQueue;

private:
	// Client side handling of being picked up
	UFUNCTION(NetMulticast, Unreliable)
		void ClientOnPickedUpBy(APawn* Pawn);
	void ClientOnPickedUpBy_Implementation(APawn* Pawn);

	FTimerHandle RespawnTimer;
};
