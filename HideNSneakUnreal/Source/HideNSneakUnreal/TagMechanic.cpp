<<<<<<< HEAD
//Author: Olle Frid

#include "TagMechanic.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayTagsModule.h"
#include "GameplayTagsSettings.h"
#include "GameplayTags.h"
#include "GameplayTagsManager.h"
#include "GameFramework/Actor.h"

// Sets default values
ATagMechanic::ATagMechanic() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CapComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &ATagMechanic::OnCompHit);

	RootComponent = MyComp;
}

// Called when the game starts or when spawned
void ATagMechanic::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ATagMechanic::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

//Checks if collision has occurred
//HitComp is this ATagMechanic
//OtherActor is whatever actor this objects bumps into
void ATagMechanic::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){

	if (OtherActor->IsA(ATagMechanic::StaticClass()) && OtherActor != this && !Cast<ATagMechanic>(OtherActor)->isSeeker) {
		targetActor = OtherActor;
		targetTagMechanic = Cast<ATagMechanic>(targetActor);
		TurnIntoSeeker();
	}
}

//Plays when someone gets turned into a seeker
//Basically just flips a boolean to true
void ATagMechanic::TurnIntoSeeker() {
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Someone has been turned into a Seeker!")));
	targetTagMechanic->isSeeker = true;
=======
//Author: Olle Frid

#include "TagMechanic.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayTagsModule.h"
#include "GameplayTagsSettings.h"
#include "GameplayTags.h"
#include "GameplayTagsManager.h"
#include "GameFramework/Actor.h"

// Sets default values
ATagMechanic::ATagMechanic() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CapComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &ATagMechanic::OnCompHit);

	RootComponent = MyComp;
}

// Called when the game starts or when spawned
void ATagMechanic::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ATagMechanic::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

//Checks if collision has occurred
//HitComp is this ATagMechanic
//OtherActor is whatever actor this objects bumps into
void ATagMechanic::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){

	if (OtherActor->IsA(ATagMechanic::StaticClass()) && OtherActor != this && !Cast<ATagMechanic>(OtherActor)->isSeeker && Cast<ATagMechanic>(this)->isSeeker) {
		targetActor = OtherActor;
		targetTagMechanic = Cast<ATagMechanic>(targetActor);
		TurnIntoSeeker();
	}
}

//Plays when someone gets turned into a seeker
//Basically just flips a boolean to true
void ATagMechanic::TurnIntoSeeker() {
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Someone has been turned into a Seeker!")));
	targetTagMechanic->isSeeker = true;
>>>>>>> Aulin
}