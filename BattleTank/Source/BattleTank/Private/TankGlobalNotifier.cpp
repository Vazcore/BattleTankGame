// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGlobalNotifier.h"
#include "Engine/Classes/GameFramework/Actor.h"
#include "Engine/Classes/Engine/World.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

// Sets default values for this component's properties
UTankGlobalNotifier::UTankGlobalNotifier()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UTankGlobalNotifier::BeginPlay()
{
	Super::BeginPlay();
	FString OwnerName = GetOwner()->GetName();
}


// Called every frame
void UTankGlobalNotifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

