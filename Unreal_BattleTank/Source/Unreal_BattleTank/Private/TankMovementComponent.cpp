// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

// Intialize the track
void UTankMovementComponent::InitializeTrack(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Dir) {
	UE_LOG(LogTemp, Warning, TEXT("Move forward is called with dir %f"), Dir);
	LeftTrack->SetThrottle(Dir);
	RightTrack->SetThrottle(Dir);
};

