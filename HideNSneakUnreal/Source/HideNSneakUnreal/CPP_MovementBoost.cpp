//Primary Author: Abdifatah Abdi

#include "CPP_MovementBoost.h"
#include <Components/BoxComponent.h>
#include <Engine/Engine.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ACPP_MovementBoost::ACPP_MovementBoost() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(70.f, 70.f, 70.f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACPP_MovementBoost::OnOverlapBegin);

	//Setting the mesh

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovementSpeed"));
	Mesh->SetupAttachment(RootComponent);

	//Set the location and size of the mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Powerup(TEXT("/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule"));
	if (Powerup.Succeeded()) {
		Mesh->SetStaticMesh(Powerup.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Mesh->SetWorldScale3D(FVector(1.f));
	}
}

void ACPP_MovementBoost::BeginPlay() { Super::BeginPlay(); }

void ACPP_MovementBoost::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ACPP_MovementBoost::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	Character = Cast<AHideNSneakCPPCharacter>(OtherActor);

	//Add the speedboost.
	if (bPowerActive && Character != NULL) {
		bPowerActive = false;
		Character->GetCharacterMovement()->MaxWalkSpeed += Speedincrease;
		GetWorld()->GetTimerManager().SetTimer(PowerTimerHandle, this, &ACPP_MovementBoost::ResetPowers, Duration, false);
		GetWorld()->GetTimerManager().SetTimer(PowerRespawnTimerHandle, this, &ACPP_MovementBoost::RespawnPowerup, RespawnTime, false);
		this->SetActorHiddenInGame(true);
		this->SetActorEnableCollision(false);
	}
}

//Remove the Speedboost
void  ACPP_MovementBoost::ResetPowers() {
	bPowerActive = true;
	Character->GetCharacterMovement()->MaxWalkSpeed = OriginalSpeed;
	GetWorld()->GetTimerManager().ClearTimer(PowerTimerHandle);
}

void ACPP_MovementBoost::RespawnPowerup() {
	GetWorld()->GetTimerManager().ClearTimer(PowerRespawnTimerHandle);
	this->SetActorHiddenInGame(false);
	this->SetActorEnableCollision(true);
}