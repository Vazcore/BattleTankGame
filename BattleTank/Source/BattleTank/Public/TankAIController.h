// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	ATank* GetControlledActor() const;
	ATank* GetPlayerTank() const;
	ATank* OwnerActor = nullptr;
	ATank* PlayerTank = nullptr;
public:
	ATankAIController();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
