// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Get the tank's aiming position
	void AimLocation(FVector HitLocation, float LaunchSpeed);

	// Set the barrel component
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Set the turret component
	void SetTurretReference(UTankTurret* TurretToSet);

private:
	
	//The barrel component
	UTankBarrel* Barrel = nullptr;
	
	//The turret component
	UTankTurret* Turret = nullptr;

	// Move the barrel to the aiming direction
	void MovingBarrelTowardAiming(FVector AimingDirection);

	// Move the turret to the aiming direction
	void MovingTurretTowardAiming(FVector AimingDirection);
};
