// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Create a delegate function to receIve the death event
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class UNREAL_BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	// The damage function called by engine
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// Calculate the percent of the HP
	UFUNCTION(BlueprintPure, Category = "HP")
	float PercentOfHP();

	// The death delegate event
	FTankDelegate TankDeath;

private:
	
	// Tank total HP in game
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float TotalHP = 60.0f;

	// Current HP in the game
	UPROPERTY(VisibleAnywhere, Category = "HP")
	float CurrentHP = TotalHP;

	// Sets default values for this pawn's properties
	ATank();
	
};
