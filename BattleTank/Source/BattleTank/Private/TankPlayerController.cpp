// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Beginning!!!"));
	ATank* Tank = GetControlledTank();

	if (Tank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Tank: %s"), *(Tank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}



