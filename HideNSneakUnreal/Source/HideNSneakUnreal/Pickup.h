//Author: Abdi Abdifatah
//Co Authors: Oskar Johansson, Alexander Aulin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "HideNSneakCPPCharacter.h"
#include "Pickup.generated.h"

class AHideNSneakCPPCharacter;

UCLASS()
class HIDENSNEAKUNREAL_API APickup : public AActor
{
	GENERATED_BODY()

public:
	/** Set default values via Constructor */
	APickup(const FObjectInitializer& OI);

	void BeginPlay() override;

	/** Required Network Scaffolding */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool DoesSpawnParticles();

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
		virtual void PickedUpBy(ACharacter* Character);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Pickup")
		// Applies the powerup effect to the received character and adds them to the queue
		void ApplyPowerUp(ACharacter* Character);
	virtual void ApplyPowerUp_Implementation(ACharacter* Character);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "Pickup")
		// Requests the server to replicate the power up on all clients
		void ClientApplyPowerUp(ACharacter* Character);
	void ClientApplyPowerUp_Implementation(ACharacter* Character);

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Pickup")
		// Deactivates the powerup effect on the next player in the queue
		void UnApplyPowerUp();
	virtual void UnApplyPowerUp_Implementation();

protected:
	/** True when the pickup can be used, false when deactivated */
	UPROPERTY(ReplicatedUsing = OnRep_IsActive)
		bool bIsActive;

	/** This is called whenever bIsActive is updated */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		virtual void OnRep_IsActive();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup", meta = (BlueprintProtected = "true"))
		// This is called on BeginPlay and whenever the pickup respawns. It is implemented in blueprints
		void OnSpawn();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup", meta = (BlueprintProtected = "true"))
		// This is called when picked up. It is implemented in blueprints
		void OnPickedUp();

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

	// Check true if this should spawn particles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		bool SpawnsParticles;

	// Check true if this should make the particle system follow the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		bool AttachParticlesToCharacter;

	// The name of the socket on the character the particles should be attached to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		FName SocketToAttachParticlesTo;

	// Particles to spawn on the character when activated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (BlueprintProtected = "true"))
		class UParticleSystem* Particles;

	UFUNCTION(BlueprintCallable, Category = "Pickup", meta = (BlueprintProtected = "true"))
		// Respawns the pickup
		virtual void RespawnPickup();

	// Queue used to keep track of which player's poweup effect should be deactivated next
	std::queue<AHideNSneakCPPCharacter*> PlayerQueue;

	std::queue<UParticleSystemComponent*> ParticleComponents;

private:
	UPROPERTY(Category = SkeletalMeshActor, VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|SkeletalMesh", AllowPrivateAccess = "true"))
		class USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collider", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* BoxComponent;

	UFUNCTION(NetMulticast, Unreliable)
		// Client side handling of being picked up
		void ClientOnPickedUpBy(ACharacter* Character);
	void ClientOnPickedUpBy_Implementation(ACharacter* Character);

	// Timer handle used to time respawning
	FTimerHandle RespawnTimer;
};