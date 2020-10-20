//Author: Olle Frid

#include "TagMechanic.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayTagsModule.h"
#include "GameplayTagsSettings.h"
#include "GameplayTags.h"
#include "GameplayTagsManager.h"

// Sets default values
ATagMechanic::ATagMechanic() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapComp"));
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

void ATagMechanic::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){
	if ((targetActor != OtherActor) && OtherActor->ActorHasTag(TEXT("Hider"))) {

		targetActor = OtherActor;

		/*for (int i = 0; i < targetActor->Children.Num(); i++)
		{
			
		}*/

		/*if (OtherActor->FindComponentByClass<ATagMechanic>() != NULL) {

			targetTagMechanic = OtherActor->FindComponentByClass<ATagMechanic>();
			targetTagMechanic->isHider = true;
		}*/
	}

	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherActor->ActorHasTag(TEXT("Hider")) && this->ActorHasTag(TEXT("Seeker"))) {

		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("HIDER*************")));
		
	}
}