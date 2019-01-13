// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/Classes/Engine/World.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

ATankAIController::ATankAIController() 
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	OwnerActor = GetControlledActor();
	
	ATank* Player = GetPlayerTank();
	if (OwnerActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s has appeared!"), *(OwnerActor->GetName()));
	}

	if (Player == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank didn't find a Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank found a Player Tank: %s"), *(Player->GetName()));
	}	
}

ATank* ATankAIController::GetControlledActor() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerTank == nullptr) {
		PlayerTank = GetPlayerTank();
		UE_LOG(LogTemp, Warning, TEXT("Ticking"));
	}
	else {
		PrimaryActorTick.bCanEverTick = false;
		SetActorTickEnabled(false);
		UE_LOG(LogTemp, Warning, TEXT("Stopped Ticking"));
	}
}