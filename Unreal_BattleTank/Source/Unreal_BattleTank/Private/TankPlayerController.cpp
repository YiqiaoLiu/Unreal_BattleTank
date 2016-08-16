// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"


// Called when game begin
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UTankAimingComponent* AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent != nullptr) {
		FindAimingComponent(AimingComponent);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Cannot find aiming component at begin play"));
	}
}

// Called in every frame
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!GetControlledTank()) return;
	//UE_LOG(LogTemp, Warning, TEXT("Player Tank Tick function check"));

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimLocation(HitLocation);
	}
}

// Get the pawn of the player tank
ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair() {
	if (!GetControlledTank()) return;
}

// Get the player tank aiming location
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {

	// Calculate the Crosshair screen location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX * CrosshairLocationX, ViewportSizeY * CrosshairLocationY);

	// Make a transform from screen location to world location
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// Do the raycast to define the fire location
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

// Get the tank look direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

// Get the hit location by ray-casting
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	FHitResult HitRes;
	FVector StartLoc = PlayerCameraManager->GetCameraLocation();
	FVector EndLoc = StartLoc + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitRes,
		StartLoc,
		EndLoc,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitRes.Location;
		return true;
	}
	else {
		HitLocation = FVector(0.0f);
		return false;
	}
}




