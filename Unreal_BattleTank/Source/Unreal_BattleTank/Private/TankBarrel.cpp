// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankBarrel.h"

// Elevate the barrel component with relative speed(-1 means minimum, 1 means maximum)
void UTankBarrel::Elevate(float RelativeElevateSpeed) {

	// Clamp the elevate speed
	RelativeElevateSpeed = FMath::Clamp(RelativeElevateSpeed, -1.0f, 1.0f);

	// Calculate and set the elevation status and clamp the pitch degree
	float ElevationChange = RelativeElevateSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	float RawTargetElevation = RelativeRotation.Pitch + ElevationChange;
	float FinalElevation = FMath::Clamp<float>(RawTargetElevation, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(FinalElevation, 0, 0));
	
	UE_LOG(LogTemp, Warning, TEXT("The Elevate is %f"), RelativeRotation.Pitch);
}

