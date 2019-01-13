// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	ATank* Tank = GetControlledActor();
	if (Tank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s has appeared!"), *(Tank->GetName()));
	}
}

ATank* ATankAIController::GetControlledActor() const
{
	return Cast<ATank>(GetPawn());
}

