// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	// Get the player tank and the AI tank itself
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!ControlledTank) return;
	else {
		// Moving the AI tank

		MoveToActor(PlayerTank, AcceptanceDistance);

		// Firing to the player tank
		ControlledTank->AimLocation(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}

}




