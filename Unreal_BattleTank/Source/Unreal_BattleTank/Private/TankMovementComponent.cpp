// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

// Initialize the track
void UTankMovementComponent::InitializeTrack(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

// Make the tank move forward or backward
void UTankMovementComponent::IntendMoveForward(float Dir) {
	//UE_LOG(LogTemp, Warning, TEXT("Move forward is called with dir %f"), Dir);
	if (!LeftTrack || !RightTrack) {
		return;
	}
	LeftTrack->SetThrottle(Dir);
	RightTrack->SetThrottle(Dir);
};

// Make the tank turn left or right
void UTankMovementComponent::IntendTurn(float Dir) {
	LeftTrack->SetThrottle(Dir);
	RightTrack->SetThrottle(-Dir);
}

// Make the AI tank move
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

	// Get the current AI tank forward vector
	FVector CurrForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

	// Get the unit direction vector toward the target
	FVector TargetDir = MoveVelocity.GetSafeNormal();

	// Calculate the dot product and pass it into the IntendMoveForward function
	// How fast will AI tank move forward/backward
	float MoveDir = FVector::DotProduct(CurrForward, TargetDir);
	IntendMoveForward(MoveDir);

	// Calculate the cross product and pass it into the IntendTurn function
	// How fast will AI tank turning
	float TurnDir = FVector::CrossProduct(CurrForward, TargetDir).Z;
	IntendTurn(TurnDir);
	
}



