// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankPlayerController.h"
#include "Engine/Classes/Engine/World.h"
#include "Engine/Public/DrawDebugHelpers.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Beginning!!!"));
	Tank = GetControlledTank();
	World = GetWorld();

	if (Tank != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Tank: %s"), *(Tank->GetName()));
		//UpdatePlayerViewPoint(Tank);
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector LineTraceEnd = FVector();

	if (Tank != nullptr) {
		/*LineTraceEnd = GetLineTraceEnd();
		DrawLine(LineTraceEnd);
		ATank* ReachedTank = GetReachedTank(LineTraceEnd);*/
		
		AimTowardsCrosshair();
	}
}

void ATankPlayerController::UpdatePlayerViewPoint(ATank* Tank) {
	Tank->GetController()->GetPlayerViewPoint(OUT ViewPoint, OUT ViewRotator);
}

FVector ATankPlayerController::GetLineTraceEnd()
{
	UpdatePlayerViewPoint(Tank);
	FVector LineTraceDirection = ViewRotator.Vector() * 20000.f;
	return ViewPoint + LineTraceDirection;
}

void ATankPlayerController::DrawLine(FVector LineTraceEnd)
{
	//UE_LOG(LogTemp, Warning, TEXT("Drawing: %s"), *(FString::SanitizeFloat(ViewPoint.X)) );
	DrawDebugLine(
		World,
		ViewPoint,
		LineTraceEnd,
		FColor(255,0,0),
		false,
		0.f,
		0.f,
		10.f
	);
}

ATank * ATankPlayerController::GetReachedTank(FVector LineTraceEnd) const
{
	FHitResult Hit;
	ATank* ReachedTank = nullptr;
	
	FCollisionQueryParams AdditionalParams = FCollisionQueryParams(
		FName(TEXT("")),
		false,
		Tank
	);

	World->LineTraceSingleByObjectType(
		Hit,
		ViewPoint,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody)
	);

	if (Hit.GetActor() != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Reached to Tank: %s"), *(Hit.GetActor()->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nothing to reach!!!"));
	}

	return ReachedTank;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) {
		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(
		ViewportSizeX * CrossHairXLocation,
		ViewportSizeY * CrossHairYLocation
	);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector WorldCameraLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		OUT WorldCameraLocation,
		OUT LookDirection
	);
}


