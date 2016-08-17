// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankTrack.h"

// Constructor
UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = true;
}

// Call it every frame
void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) {
	
	// Calculate the turning speed
	float TurningSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	// Calculate the acceleration
	FVector TurningAcceleration = -TurningSpeed / DeltaTime * GetRightVector();

	// Calculate the force add to the track
	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector TurningForceApplied = TankRoot->GetMass() * TurningAcceleration / 2; // 2 track

	// Add the force in the track
	TankRoot->AddForce(TurningForceApplied);

}

// Add force in the track
void UTankTrack::SetThrottle(float Throttle) {

	// Apply a force in the track
	FVector ForceApplied = GetForwardVector() * Throttle * MaxTrackForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* RootTank = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	RootTank->AddForceAtLocation(ForceApplied, ForceLocation);
}


