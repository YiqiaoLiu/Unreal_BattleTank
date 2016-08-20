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

	// The particle system of Impact projectile
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ImpactBlast = nullptr;

	// The radial force of the projectile
	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* ExplosionForce = nullptr;

	// The time the projectile will be destroy after hit something
	float DestroyDelay = 2;

	// The damage of each projectile
	float ProjectileDamage = 20.0f;

	// Hit detection of the projectile
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
	// The destroy function of the projectile
	void DestroyTimeDelay();
};
