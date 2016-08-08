// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankBarrel.h"

// Elevate the barrel component
void UTankBarrel::Elevate(float DegreePerSecond) {
	UE_LOG(LogTemp, Warning, TEXT("The Elevate be called with speed %f"), DegreePerSecond);
}

