// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankPlayerController.h"


// Called when game begin
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;
	FindAimingComponent(AimingComponent);
}

// Set the pawn of the player tank
void ATankPlayerController::SetPawn(APawn* InPawn) {

	Super::SetPawn(InPawn);
	// Pointer protect
	if (!InPawn) return;

	ATank* PossessedTank = Cast<ATank>(InPawn);
	// Pointer protect
	if (!ensure(PossessedTank)) return;

	PossessedTank->TankDeath.AddUniqueDynamic(this, &ATankPlayerController::PlayerTankDeathEvent);
}

// Called in every frame
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!ensure(GetPawn())) return;
	//UE_LOG(LogTemp, Warning, TEXT("Player Tank Tick function check"));

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;
	FVector HitLocation;

	bool GetAiming = GetSightRayHitLocation(HitLocation);
	if (GetAiming) {
		AimingComponent->AimLocation(HitLocation);
	}
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
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
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

// Receive the death event
void ATankPlayerController::PlayerTankDeathEvent() {
	StartSpectatingOnly();
}




