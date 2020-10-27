// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPPCharacter.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API ACPPCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	/** Collection Sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Battery, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;

	// Variable collection sphere radius, can be changed in the editor
	UPROPERTY(Replicated, VisibleAnywhere, Category = Battery, meta = (AllowPrivateAcces = "true"))
		float CollectionSphereRadius;



public:
	ACPPCharacter();

	/** Required Network Scaffolding */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:

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

	// Entry point for collecting pickups, called when the player presses a key to collect pickups
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void CollectPickups();

	// Called on the Server to proccess collection of pickups
	UFUNCTION(Reliable, Server, WithValidation)
		void ServerCollectPickups();

	bool ServerCollectPickups_Validate();

	virtual void ServerCollectPickups_Implementation();

	// The characters initial power level
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
		float InitialPower;

	// Base speed when power is zero
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
		float BaseSpeed;

	// Multiplier for controlling current speed depending on power level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
		float SpeedFactor;

	// Update character visuals based on power level
	UFUNCTION(BlueprintImplementableEvent, Category = "Power")
		void PowerChangeEffect();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns CollectionSphere subobject **/
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }
	// Returns the character's initial power
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetInitialPower() const { return InitialPower; }
	// Returns the character's current power
	UFUNCTION(BlueprintPure, Category = "Power")
		float GetCurrentPower() const { return CurrentPower; }
	// Update the character's current power
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Power")
		void UpdatePower(float DeltaPower);

private:
	// The current power level of the character
	UPROPERTY(ReplicatedUsing = OnRep_CurrentPower, VisibleAnywhere, Category = "Power")
		float CurrentPower;

	// Power level is updated on client
	UFUNCTION()
		void OnRep_CurrentPower();

};
