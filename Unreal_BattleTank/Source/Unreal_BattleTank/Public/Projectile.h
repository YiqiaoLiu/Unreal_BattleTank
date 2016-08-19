// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class UNREAL_BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Launch the projectile
	void LaunchProjectile(float LaunchSpeed);

private:
	
	// The projectile movement component
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	// The collison of the projectile
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;

	// The particle system of launch projectile
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* LaunchBlast = nullptr;
	
};
