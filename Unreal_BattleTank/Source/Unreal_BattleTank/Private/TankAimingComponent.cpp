// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = false;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Get the aiming location
void UTankAimingComponent::AimLocation(FVector HitLocation) {

	// If cannot find the barrel, return
	if (!ensure(Barrel)) return;

	// Set the projectile launch
	FVector StartLoc = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLoc = HitLocation;
	FVector OutLaunchSpeed;

	bool IsLaunchSetting = UGameplayStatics::SuggestProjectileVelocity(
									this,
									OutLaunchSpeed,
									StartLoc,
									EndLoc,
									LaunchSpeed,
									false,
									0,
									0,
									ESuggestProjVelocityTraceOption::DoNotTrace
								);

	// If launch success
	if (IsLaunchSetting) 
	{
		FVector AimDirection = OutLaunchSpeed.GetSafeNormal();
		MovingBarrelTowardAiming(AimDirection);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Target Missing"));
	}
}

// Initialize the barrel and turret component
void UTankAimingComponent::InitializeAimingComponent(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet) {
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

// Moving the barrel to the aiming direction
void UTankAimingComponent::MovingBarrelTowardAiming(FVector AimingDirection) {

	// Pointer protect
	if (!Barrel || !Turret) return;

	// Get the rotation of the barrel and the target
	FRotator BarrelCurrentRot = Barrel->GetForwardVector().Rotation();
	FRotator AimingRot = AimingDirection.Rotation();
	FRotator DeltaRot = AimingRot - BarrelCurrentRot;

	// Moving the barrel component
	Barrel->Elevate(DeltaRot.Pitch);
	Turret->Whirl(DeltaRot.Yaw);
}

// The fire operation of player tank
void UTankAimingComponent::Fire() {

	// Check the fire time
	bool IsFireReady = FPlatformTime::Seconds() - LastFireTime > FireRate;

	// Get the projectile info
	if (!ensure(Barrel)) return;
	FVector ProjectileLoc = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator ProjectileRot = Barrel->GetSocketRotation(FName("Projectile"));

	// Judge whether launch the projectile based on the fire rate and set the last fire time
	if (IsFireReady) {
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(Projectile_BP, ProjectileLoc, ProjectileRot);
		if (!ensure(Projectile)) return;
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}



