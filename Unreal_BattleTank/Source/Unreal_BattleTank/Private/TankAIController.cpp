// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	else {
		// Moving the AI tank

		MoveToActor(GetWorld()->GetFirstPlayerController()->GetPawn(), AcceptanceDistance);

		auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(AimingComponent)) return;
		// Firing to the player tank
		AimingComponent->AimLocation(PlayerTank->GetActorLocation());
		AimingComponent->Fire();
	}

}




