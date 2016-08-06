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

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Get the player tank and name is: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("The player tank is MISSING"));
	}
}

ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}




