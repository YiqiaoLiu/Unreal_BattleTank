// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

// Forward declaration
class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREAL_BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	// Initialize the track component
	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitializeTrack(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	// Make the tank move forward (dir = 1) or backward (dir = -1)
	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendMoveForward(float Dir);

	// Make the tank turn right (dir = 1) or turn left (dir = -1)
	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendTurn(float Dir);

	// Make the AI tank moving
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
private:

	// Store the 2 tracks
	UTankTrack* LeftTrack;
	UTankTrack* RightTrack;

};
