// Primary Author: Abdifatah


#include "CPP_Powerup.h"
#include <Components/BoxComponent.h>
#include <Engine/Engine.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ACPP_Powerup::ACPP_Powerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(70.f, 70.f, 70.f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this,&ACPP_Powerup::OnOverlapBegin);

	//Setting the mesh

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My PowerUp"));
	Mesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Powerup(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid"));
	if (Powerup.Succeeded()) {
		Mesh->SetStaticMesh(Powerup.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Mesh->SetWorldScale3D(FVector(1.f));
	}

}

// Called when the game starts or when spawned
void ACPP_Powerup::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ACPP_Powerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Powerup::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<AHideNSneakCPPCharacter>(OtherActor);

	
	//Give the player invisibility for x amount of seconds.
	if (bPowerActive&& Character!=NULL){
		this->SetActorHiddenInGame(true);
		this->SetActorEnableCollision(false);
		bPowerActive = false;
		GetWorld()->GetTimerManager().SetTimer(PowerTimerHandle, this, &ACPP_Powerup::ResetPowers, duration, false);	
		GetWorld()->GetTimerManager().SetTimer(PowerRespawnTimerHandle, this, &ACPP_Powerup::RespawnPowerup, RespawnTime, false);
		Character->GetMesh()->SetVisibility(false);
		
	}

	
	
}

//Removes the invisibility
void ACPP_Powerup::ResetPowers()
{
	bPowerActive = true;
	/*Character->GetCharacterMovement()->MaxWalkSpeed = 600;
	Character->GetCharacterMovement()->JumpZVelocity = 700;
	Character->JumpMaxCount = 1;*/
	Character->GetMesh()->SetVisibility(true);
	GetWorld()->GetTimerManager().ClearTimer(PowerTimerHandle);

	}

void ACPP_Powerup::RespawnPowerup()
{
	this->SetActorHiddenInGame(false);
	this->SetActorEnableCollision(true);
	GetWorld()->GetTimerManager().ClearTimer(PowerRespawnTimerHandle);
}

