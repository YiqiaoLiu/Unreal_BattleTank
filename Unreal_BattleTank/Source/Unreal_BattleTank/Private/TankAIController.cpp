// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "Tank.h"
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

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!GetAITank()) return;
	else {
		GetAITank()->AimLocation(GetPlayerTank()->GetActorLocation());
	}

}

// Get the AI tank pawn
ATank* ATankAIController::GetAITank() const {
	return Cast<ATank>(GetPawn());
}

// Get the player tank in order to aiming
ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}




