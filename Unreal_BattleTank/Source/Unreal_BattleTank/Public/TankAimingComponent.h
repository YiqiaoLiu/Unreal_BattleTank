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
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Get the tank's aiming position
	void AimLocation(FVector HitLocation);

	// Player's tank Fire operation
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

	// Initialize the barrel and turret component
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void InitializeAimingComponent(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	// Get the firing status
	EFiringStatus GetFiringStatus() const;

protected:

	// Create and initialize the firing status
	UPROPERTY(BlueprintReadOnly, Category = "Status")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

private:
	
	//The barrel component
	UTankBarrel* Barrel = nullptr;
	
	//The turret component
	UTankTurret* Turret = nullptr;

	// The launch speed
	float LaunchSpeed = 10000.0f;

	// The AI tank fire rate in seconds
	float FireRate = 3;

	// Store last fire time
	double LastFireTime = 0;

	// Get the aiming direction
	FVector AimDirection;

	// The projectile blueprint
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> Projectile_BP;

	// Call it when game begin play
	virtual void BeginPlay() override;

	// Call it every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;

	// Move the barrel to the aiming direction
	void MovingBarrelTowardAiming(FVector AimingDirection);

	// Check whether the tank is aiming
	bool IsTankAiming();
};
