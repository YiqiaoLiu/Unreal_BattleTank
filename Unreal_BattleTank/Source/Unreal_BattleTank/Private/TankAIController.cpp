// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PossessAITank = GetAITank();
	if (PossessAITank) {
		UE_LOG(LogTemp, Warning, TEXT("The AI tank name is: %s"), *PossessAITank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The AI tank is MISSING"));
	}
}

ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}




