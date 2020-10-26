// Primary Author: Abdifatah Abdi


#include "CPP_Character.h"

// Sets default values
ACPP_Character::ACPP_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;


	//PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bCrouchMaintainsBaseLocation = true;
	GetCharacterMovement()->JumpZVelocity = 700;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);

	
}



// Called when the game starts or when spawned
void ACPP_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPP_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPP_Character::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released,this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed,this, &ACPP_Character::OnCrouch);
	PlayerInputComponent->BindAction(");


}

void ACPP_Character::MoveForward(float axis)
{
	const FRotator control_rotation = Controller->GetControlRotation();
	const FRotator control_rotation_yawonly = FRotator(0, control_rotation.Yaw, 0);
	const FVector fwd = FRotationMatrix(control_rotation_yawonly).GetUnitAxis(EAxis::X);

	AddMovementInput(fwd, axis);
}

void ACPP_Character::MoveRight(float axis)
{
	const FRotator control_rotation = Controller->GetControlRotation();
	const FRotator control_rotation_yawonly = FRotator(0, control_rotation.Yaw, 0);
	const FVector right = FRotationMatrix(control_rotation_yawonly).GetUnitAxis(EAxis::Y);

	AddMovementInput(right, axis);
}

void ACPP_Character::OnCrouch()
{
	if (!Crouching) {
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Activate SneakMode");
		
		GetCharacterMovement()->Crouch();
		GetCharacterMovement()->bWantsToCrouch = 1;
		Crouching = true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Deactivate SneakMode");
		GetCharacterMovement()->UnCrouch();
		GetCharacterMovement()->bWantsToCrouch = 0;
		Crouching = false;
	}
		
}

