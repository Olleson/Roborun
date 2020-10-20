//Author: Olle Frid

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TagMechanic.generated.h"

UCLASS()
class HIDENSNEAKUNREAL_API ATagMechanic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATagMechanic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UCapsuleComponent* MyComp;

	UPROPERTY(EditAnywhere)
		bool isHider;

	UPROPERTY(EditAnywhere)
		AActor* targetActor;

	UPROPERTY(VisibleAnywhere)
		ATagMechanic* targetTagMechanic;

	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};