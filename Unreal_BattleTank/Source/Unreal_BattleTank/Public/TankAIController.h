// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class UNREAL_BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	// Receive the death event from Tank
	UFUNCTION()
	void AITankDeathEvent();
	
	// How close AI tank could move to player tank before firing
	float AcceptanceDistance = 7000;
};
