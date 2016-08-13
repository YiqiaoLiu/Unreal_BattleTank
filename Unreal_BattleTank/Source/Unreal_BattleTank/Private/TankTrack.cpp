// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {

	// Apply a force in the track
	FVector ForceApplied = GetForwardVector() * Throttle * MaxTrackForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* RootTank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	RootTank->AddForceAtLocation(ForceApplied, ForceLocation);
}


