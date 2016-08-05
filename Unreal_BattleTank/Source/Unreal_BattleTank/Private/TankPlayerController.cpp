// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto PossessedTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController work!"));

	if (PossessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("The controller tank is: %s"), *PossessedTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The controller tank is MISSING"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const {
	//if (GetPawn()) {
	//	UE_LOG(LogTemp, Warning, TEXT("The controller tank is: %s"), *GetPawn()->GetName());
	//}
	return Cast<ATank>(GetPawn());
}


