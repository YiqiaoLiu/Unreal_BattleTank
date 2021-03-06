// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankTurret.h"

// Whirling the turret component based on relative speed(1.0 is the maximum speed)
void UTankTurret::Whirl(float RelativeSpeed) {

	// Clamp the relative speed
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	// Get the turret current rot and target rot
	float TurretRotChange = RelativeSpeed * TurretMaxRotSpeed * GetWorld()->DeltaTimeSeconds;
	float FinalWhirl = RelativeRotation.Yaw + TurretRotChange;

	SetRelativeRotation(FRotator(0.0f, FinalWhirl, 0.0f));
}



