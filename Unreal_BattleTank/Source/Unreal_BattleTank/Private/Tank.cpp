// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAimingComponent.h"
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
	UE_LOG(LogTemp, Warning, TEXT("%s is firing"), *GetName());
	if (!Barrel) return;
	FVector ProjectileLoc = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator ProjectileRot = Barrel->GetSocketRotation(FName("Projectile"));
	UE_LOG(LogTemp, Warning, TEXT("Projectile loc is: %s"), *ProjectileLoc.ToString());
	GetWorld()->SpawnActor<AProjectile>(Projectile_BP, ProjectileLoc, ProjectileRot);
}

