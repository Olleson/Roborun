//author: Oskar Johansson
// Fill out your copyright notice in the Description page of Project Settings.


#include "moveableBox.h"
#include "Math/Vector.h"
// Sets default values for this component's properties
UmoveableBox::UmoveableBox()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UmoveableBox::BeginPlay()
{
	Super::BeginPlay();
	// this is a good idea but it doesnt work as of now since the selfactor->children.num() = 0;
	for (int i = 0; i <(SelfActor->Children.Num() - 1); i++) {
		if (SelfActor->Children[i]->GetName()== "End") {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("WE did it"));
		}
	}

	if (SelfActor && Endpoint) {
	StartPosition = SelfActor->GetTransform().GetLocation();
	//EndPosition = Endpoint->GetComponentLocation();
	/*EndPosition = Endpoint->GetTransform().GetLocation();*/
	TargetPosition = EndPosition;
	movementvecktor = (EndPosition - StartPosition).GetSafeNormal() * MovementSpeed;
	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("wtf"));
	// ...
}

//void UmoveableBox::SetActors(AActor *selfActor, AActor *endpoint) {
//	selfActor = SelfActor;
//	endpoint = Endpoint;
//}


// Called every frame
void UmoveableBox::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SelfActor && Endpoint) {
		if ((TargetPosition - SelfActor->GetTransform().GetLocation()).Size() > MovementSpeed) {
			SelfActor->SetActorLocation(SelfActor->GetTransform().GetLocation() + movementvecktor);
		}
		else
		{
			if (TargetPosition == StartPosition) {
				TargetPosition = EndPosition;
				movementvecktor = (EndPosition - StartPosition).GetSafeNormal() * MovementSpeed;
			}
			else {
				TargetPosition = StartPosition;
				movementvecktor = (StartPosition - EndPosition).GetSafeNormal() * MovementSpeed;
			}
		}
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("You did not set the Endpoint or "));
	}
	//else {
	//	if (TargetPosition == EndPosition) {
	//		TargetPosition = StartPosition;
	//	}
	//	else
	//	{
	//		TargetPosition = EndPosition;
	//	}
	//	GEngine->AddOnScreenDebugMessage(-1, 0.25f, FColor::Yellow, TEXT("körs denna?"));
	//}
	///*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("wtf"));*/
		//SelfActor->GetTransform();
	// ...
}

