//Author: Abdi Abdifatah
//Co Author: Oskar Johansson
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Pickup.generated.h"

/**
 * 
 */
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

protected:
	/** True when the pickup can be used, false when deactivated */
	UPROPERTY(ReplicatedUsing = OnRep_IsActive)
		bool bIsActive;

	/** This is called whenever bIsActive is updated */
	UFUNCTION()
		virtual void OnRep_IsActive();

	// The pawn who picked up the pickup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
		APawn* PickupInstigator;

private:
	// Client side handling of being picked up
	UFUNCTION(NetMulticast, Unreliable)
		void ClientOnPickedUpBy(APawn* Pawn);
	void ClientOnPickedUpBy_Implementation(APawn* Pawn);
};
