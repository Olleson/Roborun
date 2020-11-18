// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PowerUpInventoryItem.h"
#include "HideNSneakCPPCharacter.generated.h"

class PowerUpInventoryItem;

UCLASS()
class HIDENSNEAKUNREAL_API AHideNSneakCPPCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

public:
	AHideNSneakCPPCharacter();

	void BeginPlay() override;

	/** Required Network Scaffolding */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere)
		bool hasBeenSeeker;

	UFUNCTION(BlueprintCallable, Category = "MovementSpeed")
		// Returns the base speed of the character's current role
		float GetBaseSpeed();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		// Sets the pointer to a collected pickup
		void CollectPickup(APickup* Pickup);

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		// Consumes the current powerup
		void ConsumePowerUp();

	// Client Request to turn into a hider
	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "Seeker")
		void BecomeHider();

	void BecomeHider_Implementation();

	// Server side handling of making a player become hider
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Seeker")
		void ServerBecomeHider();

	void ServerBecomeHider_Implementation();

	// Client request to turn into a seeker
	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "Seeker")
		void BecomeSeeker();

	void BecomeSeeker_Implementation();

	// Server side handling of turning a hider into a seeker
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Seeker")
		void ServerBecomeSeeker();

	// The function that is actually called on the server, must be appended with _Implementation to compile
	void ServerBecomeSeeker_Implementation();

	// Client request to reset all players into hiders
	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "Seeker")
		void ResetPlayersToHiders();

	void ResetPlayersToHiders_Implementation();

	// Server side handling of reseting all players into hiders
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Seeker")
		void ServerResetPlayersToHiders();

	void ServerResetPlayersToHiders_Implementation();

	UPROPERTY(EditAnywhere)
		bool DecoyAvailible = true;

	UFUNCTION(Client, unreliable, BlueprintCallable, Category = "Hider")
		//make character go stealth + spawn a decoy character
		void UseDecoyAbility();
	void UseDecoyAbility_Implementation();

	UFUNCTION(Server, reliable)
		//Turns the character visible on all clients on the server
		void ServerDecoyStealthOver(AHideNSneakCPPCharacter *MyActor);
	void ServerDecoyStealthOver_Implementation(AHideNSneakCPPCharacter*MyActor);

	UFUNCTION(Server, reliable)
		//server side for handling the making of the character go stealth + spawn a decoy character
		void ServerDecoyAbility(AHideNSneakCPPCharacter *SpawnActor, FTransform DecoyTransform, FVector DecoyVelocity, float MovementValue);
	void ServerDecoyAbility_Implementation(AHideNSneakCPPCharacter *SpawnActor, FTransform DecoyTransform, FVector DecoyVelocity, float MovementValue);

	// Acces to the timer for handling the duration of the stealth
	FTimerHandle DecoyTimerHandle;
	//acces to the timer for handling the cooldown of the decoy
	FTimerHandle DecoyCooldownHandle;
	//acces to the timer for handling the duration of the Stealth
	FTimerHandle StealthTimerHandle;

	UPROPERTY(EditAnywhere)
		//The Cooldown of the Decoy
		float DecoyCooldown = 60.0f;

	UPROPERTY(EditAnywhere)
		//The duration of the stealth when you use the decoy ability
		float StealthDuration = 3.0f;

	UPROPERTY(EditAnywhere)
		//How many seconds the decoy lives after it has been spawned
		float DecoyDuration = 5.0f;

	UPROPERTY(EditAnywhere)
		//Standard movementvalue for the decoy when it spawns
		float DecoyMovementValue = 1.0f;

	UFUNCTION(Client, unreliable, Category = "Hider")
		//Turning the referenced character back to visible for all clients
		void DecoyStealthOver();
	void DecoyStealthOver_Implementation();

	UFUNCTION( Client, unreliable, category = "´Hider")
		//clears the timer for the cooldown reset and makes the decoy ability availible again
		void DecoyCooldownOver();
	void DecoyCooldownOver_Implementation();

	UFUNCTION(Client, unreliable,BlueprintCallable , Category = "Hider")
		//moves the decoy
		void MoveDecoy();
	void MoveDecoy_Implementation();


	UPROPERTY(EditAnywhere)
		AActor* targetActor;

	UPROPERTY(VisibleAnywhere)
		AHideNSneakCPPCharacter* targetTagMechanic;

	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AHideNSneakCPPCharacter> Decoy;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	// Wether this character is a seeker or hider
	UPROPERTY(ReplicatedUsing = OnRep_IsSeeker, VisibleAnywhere, BlueprintReadWrite, Category = "Seeker", meta = (BlueprintProtected = "true"))
	bool bIsSeeker;

	// Is called on clients when bIsSeeker changes
	UFUNCTION(BlueprintImplementableEvent, Category = "Seeker")
	void OnRep_IsSeeker();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed", meta = (BlueprintProtected = "true"))
		float HiderBaseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed", meta = (BlueprintProtected = "true"))
		float SeekerBaseSpeed;

	
	/*// Base speed for characters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed", meta = (BlueprintProtected = "true"))
	float BaseSpeed;

	// Multiplier for controlling current speed depending on role
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed", meta = (BlueprintProtected = "true"))
	float SpeedFactor;
	*/
	// Entry to capturing hiders
	/*UFUNCTION(BlueprintCallable, Category = "Seeker")
	void CaptureHiders();*/

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
		PowerUpInventoryItem* CollectedPowerUp;

	// Server side handling of capturing hiders
	UFUNCTION(Reliable, Server)
	void ServerCaptureHider(AHideNSneakCPPCharacter* Hider);

	void ServerCaptureHider_Implementation(AHideNSneakCPPCharacter* Hider);

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	// Returns true if the character is a seeker
	UFUNCTION(BlueprintPure, Category = "Seeker")
	bool IsSeeker() const { return bIsSeeker; }
};
