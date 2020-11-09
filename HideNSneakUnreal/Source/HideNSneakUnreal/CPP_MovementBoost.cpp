// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MovementBoost.h"
#include <Components/BoxComponent.h>
#include <Engine/Engine.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ACPP_MovementBoost::ACPP_MovementBoost()
{
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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Powerup(TEXT("/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule"));
	if (Powerup.Succeeded()) {
		Mesh->SetStaticMesh(Powerup.Object);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Mesh->SetWorldScale3D(FVector(1.f));
	}


}

// Called when the game starts or when spawned
void ACPP_MovementBoost::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<ACPP_Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	
}

// Called every frame
void ACPP_MovementBoost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_MovementBoost::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	
	if (bPowerActive&& Character != NULL) {
		bPowerActive = false;
		Character->GetCharacterMovement()->MaxWalkSpeed = 2000;
		GetWorld()->GetTimerManager().SetTimer(PowerTimerHandle, this, &ACPP_MovementBoost::ResetPowers, 5.0f, false);
		}
		
	



}

void  ACPP_MovementBoost::ResetPowers()
{
	bPowerActive = true;
	Character->GetCharacterMovement()->MaxWalkSpeed = 600;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Eureka!"));

}


