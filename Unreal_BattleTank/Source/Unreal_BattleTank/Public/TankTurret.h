// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UNREAL_BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Whirling the turret component to the aiming location
	void Whirl(float RelativeSpeed);

private:

	// The speed of turret rotate speed
	UPROPERTY(EditAnywhere)
	float TurretMaxRotSpeed = 25.0f;
	
};
