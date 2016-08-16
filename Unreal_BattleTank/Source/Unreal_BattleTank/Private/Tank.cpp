// Fill out your copyright notice in the Description page of Project Settings.

#include "Unreal_BattleTank.h"
//#include "TankAimingComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Call it when game begin
void ATank::BeginPlay() {
	Super::BeginPlay();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}


