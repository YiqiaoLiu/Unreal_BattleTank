// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class UNREAL_BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	// Get the tank controller
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;


	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FindAimingComponent(UTankAimingComponent* AimingComponent);

private:

	UPROPERTY(EditAnywhere)
	float CrosshairLocationX = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairLocationY = 0.33333f;

	float LineTraceRange = 1000000.0f;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation) const;

	bool GetLookDirection(FVector2D ScreeLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
