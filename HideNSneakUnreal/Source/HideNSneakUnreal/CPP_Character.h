// Primary Author: Abdifatah Abdi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "CPP_Character.generated.h"


UCLASS()
class HIDENSNEAKUNREAL_API ACPP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_Character();
	//Test comment

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* PlayerCamera;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* CollisionBox;
	
	//The crouch function
	UFUNCTION()
	void OnCrouch();


	
	void MoveForward(float axis);
	void MoveRight(float axis);

	//Boolean that checks if player is crouching
	bool Crouching = false;
	



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
