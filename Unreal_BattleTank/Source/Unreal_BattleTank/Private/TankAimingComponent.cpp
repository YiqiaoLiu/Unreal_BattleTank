// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
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
void UTankAimingComponent::AimLocation(FVector HitLocation, float LaunchSpeed) {

	// If cannot find the barrel, return
	if (!Barrel) return;

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

// Set the barrel component of each tank
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}

// Set the turret component of each tank
void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {
	Turret = TurretToSet;
}

// Moving the barrel to the aiming direction
void UTankAimingComponent::MovingBarrelTowardAiming(FVector AimingDirection) {

	// Get the rotation of the barrel and the target
	FRotator BarrelCurrentRot = Barrel->GetForwardVector().Rotation();
	FRotator AimingRot = AimingDirection.Rotation();
	FRotator DeltaRot = AimingRot - BarrelCurrentRot;

	// Moving the barrel component
	Barrel->Elevate(DeltaRot.Pitch);
	Turret->Whirl(DeltaRot.Yaw);
}


