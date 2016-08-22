// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class UNREAL_BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FindAimingComponent(UTankAimingComponent* AimingComponent);

private:

	// The cross hair of tank's location in the screen
	UPROPERTY(EditAnywhere)
	float CrosshairLocationX = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairLocationY = 0.33333f;

	// The fire range of tank
	float LineTraceRange = 1000000.0f;

	// Call it when game begins
	virtual void BeginPlay() override;
	
	// Call it in every frame
	virtual void Tick(float DeltaTime) override;

	// Get the player tank aiming location
	bool GetSightRayHitLocation(FVector &HitLocation) const;

	// Get the tank look direction
	bool GetLookDirection(FVector2D ScreeLocation, FVector& LookDirection) const;

	// Get the hit location by ray-casting
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// Set the pawn of the player tank
	virtual void SetPawn(APawn* InPawn) override;

	// Receive the death event
	UFUNCTION()
	void PlayerTankDeathEvent();
};
