// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

// Get the aiming location
void UTankAimingComponent::AimLocation(FVector HitLocation, float LaunchSpeed) {

	// If cannot find the barrel, return
	if (!Barrel) return;

	FVector StartLoc = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLoc = HitLocation;
	FVector OutLaunchSpeed;
	if (UGameplayStatics::SuggestProjectileVelocity(
				this,
				OutLaunchSpeed,
				StartLoc,
				EndLoc,
				LaunchSpeed,
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::DoNotTrace)
		) 
	{
		FVector AimDirection = OutLaunchSpeed.GetSafeNormal();
		FString ControlTankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming direction is: %s"), *ControlTankName, *AimDirection.ToString());
	}
}

// Set the barrel component of each tank
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
	Barrel = BarrelToSet;
}

