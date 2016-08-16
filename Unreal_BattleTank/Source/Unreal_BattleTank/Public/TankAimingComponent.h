// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Firing status enum
UENUM()
enum class EFiringStatus : uint8 {
	Reloading,
	Aiming,
	Locking
};

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

	// Initialize the barrel and turret component
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitializeAimingComponent(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

protected:

	// Create and initialize the firing status
	UPROPERTY(BlueprintReadOnly, Category = "Status")
	EFiringStatus FiringStatus = EFiringStatus::Locking;

private:
	
	//The barrel component
	UTankBarrel* Barrel = nullptr;
	
	//The turret component
	UTankTurret* Turret = nullptr;

	// Move the barrel to the aiming direction
	void MovingBarrelTowardAiming(FVector AimingDirection);
};
