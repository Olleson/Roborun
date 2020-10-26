// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Powerup.h"
#include <Components/BoxComponent.h>
#include <Engine/Engine.h>

// Sets default values
ACPP_Powerup::ACPP_Powerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(50.f, 50.f, 50.f));
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
	Destroy();
	ACPP_Character* OtherCharacter = Cast<ACPP_Character>(OtherActor);
	
	//ACharacter* Character = Cast<AActor>(OtherActor);
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Overlap Begin called");
}

