// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);

	// Pointer protect
	if (!InPawn) return;

	ATank* PossessedTank = Cast<ATank>(InPawn);
	if (!ensure(PossessedTank)) return;

	PossessedTank->TankDeath.AddUniqueDynamic(this, &ATankAIController::AITankDeathEvent);

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

		if (AimingComponent->GetFiringStatus() == EFiringStatus::Locking) {
			AimingComponent->Fire();
		}
	}

}

void ATankAIController::AITankDeathEvent() {
	
	// Pointer protect
	if (!ensure(GetPawn())) return;

	GetPawn()->DetachFromControllerPendingDestroy();
}




