// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HideNSneakCPPCharacter.generated.h"

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
		AActor* targetActor;

	UPROPERTY(VisibleAnywhere)
		AHideNSneakCPPCharacter* targetTagMechanic;

	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

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

	// Wether this character is a seeker or hider
	UPROPERTY(ReplicatedUsing = OnRep_IsSeeker, VisibleAnywhere, BlueprintReadWrite, Category = "Seeker", meta = (BlueprintProtected = "true"))
	bool bIsSeeker;

	// Is called on clients when bIsSeeker changes
	UFUNCTION(BlueprintImplementableEvent, Category = "Seeker")
	void OnRep_IsSeeker();

	// Base speed for characters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed", meta = (BlueprintProtected = "true"))
	float BaseSpeed;

	// Multiplier for controlling current speed depending on role
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed", meta = (BlueprintProtected = "true"))
	float SpeedFactor;

	// Entry to capturing hiders
	/*UFUNCTION(BlueprintCallable, Category = "Seeker")
	void CaptureHiders();*/

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

	//UFUNCTION()
	//	void Test();
	UFUNCTION()
		virtual void Tick(float DeltaSeconds);
};
