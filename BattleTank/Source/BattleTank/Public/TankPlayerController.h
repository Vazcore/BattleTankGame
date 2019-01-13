// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* Tank = nullptr;
	UWorld* World = nullptr;
	void UpdatePlayerViewPoint(ATank*);
	FVector GetLineTraceEnd();
	void DrawLine(FVector LineTraceEnd);
	ATank* GetReachedTank(FVector LineTraceEnd) const;
	FVector ViewPoint = FVector();
	FRotator ViewRotator = FRotator();
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector&) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3f;

public:
	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;
	virtual void Tick(float DeltaTime) override;
};
