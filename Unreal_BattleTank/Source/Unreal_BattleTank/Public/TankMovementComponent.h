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
	
private:
	UTankTrack* LeftTrack;
	UTankTrack* RightTrack;

};
