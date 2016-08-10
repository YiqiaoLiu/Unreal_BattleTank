// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class UNREAL_BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimLocation(FVector HitLocation);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	// Set the barrel static mesh component
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Set the turret static mesh component
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	// Player's tank Fire operation
	UFUNCTION(BlueprintCallable, Category = Fire)
	void Fire();

private:

	// The launch speed of tank projectile
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.0f;
	
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;	
	
};
