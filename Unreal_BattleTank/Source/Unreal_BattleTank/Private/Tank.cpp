// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create a sub-class of the tank aiming component
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("TankAimingComponent"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

// Get the aiming location by calling aiming component
void ATank::AimLocation(FVector HitLocation) {
	TankAimingComponent->AimLocation(HitLocation, LaunchSpeed);
}

// Get the Barrel mesh component by calling the aiming component
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

// Get the Turret mesh component by calling the aiming component
void ATank::SetTurretReference(UTankTurret* TurretToSet) {
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// The fire operation of player tank
void ATank::Fire() {

	// Check the fire time
	bool IsFireReady = FPlatformTime::Seconds() - LastFireTime > FireRate;

	// Get the projectile info
	if (!Barrel) return;
	FVector ProjectileLoc = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator ProjectileRot = Barrel->GetSocketRotation(FName("Projectile"));

	// Judge whether launch the projectile based on the fire rate and set the last fire time
	if (IsFireReady) {
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(Projectile_BP, ProjectileLoc, ProjectileRot);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

