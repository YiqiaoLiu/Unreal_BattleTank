// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UNREAL_BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// Set the force to the tank track
	UFUNCTION(BlueprintCallable, Category = "Throttle")
	void SetThrottle(float Throttle);

private:

	// The max force of the tank
	float MaxTrackForce = 10000000.0f;
};
