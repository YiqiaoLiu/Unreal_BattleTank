// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UNREAL_BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	// Function elevate the barrel
	void Elevate(float RelativeElevateSpeed);

private:
	// The elevation speed of barrel
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreePerSecond = 20.0f;

	// The max degree that barrel could be elevated
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevationDegree = 40.0f;

	// The min degree that barrel could be elevated
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevationDegree = 0.0f;
};
