// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankAimingComponent;

UCLASS()
class UNREAL_BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimLocation(FVector HitLocation);

	// Player's tank Fire operation
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:

	// Store the tank aiming component
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	//// Store the tank movement component
	//UPROPERTY(BlueprintReadOnly)
	//UTankMovementComponent* TankMovementComponent = nullptr;


private:

	// The launch speed of tank projectile
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 10000.0f;

	// The AI tank fire rate in seconds
	float FireRate = 3;

	// Store last fire time
	double LastFireTime = 0;

	// Local barrel component to launch the projectile
	UTankBarrel* Barrel = nullptr;

	// Call it when game begin
	virtual void BeginPlay() override;

	// The projectile blueprint
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> Projectile_BP;
	
	// Sets default values for this pawn's properties
	ATank();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;	
	
};
