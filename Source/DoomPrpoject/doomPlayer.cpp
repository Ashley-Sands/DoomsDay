// Fill out your copyright notice in the Description page of Project Settings.

#include "doomPlayer.h"
#include "Components/InputComponent.h"
#include "Engine.h"

// Sets default values
AdoomPlayer::AdoomPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AdoomPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AdoomPlayer::MoveForward(float scale)
{
	//if(scale != 0)
	//	GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Red, "Move Forwards");

	AddMovementInput(GetActorForwardVector(), scale);
}

void AdoomPlayer::Strafe(float scale)
{
	//if (scale != 0)
	//	GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, "Strafe");

	AddMovementInput(GetActorRightVector(), scale);

}

void AdoomPlayer::Turn(float scale)
{
	//if (scale != 0)
	//	GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Green, "Turn");

	AddControllerYawInput(scale);

}

void AdoomPlayer::Pitch(float scale)
{
	//if (scale != 0)
	//	GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Green, "Turn");

	AddControllerPitchInput(scale);

}


// Called every frame
void AdoomPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AdoomPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// get inputs
	PlayerInputComponent->BindAxis("Forwards", this, &AdoomPlayer::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AdoomPlayer::Strafe);
	PlayerInputComponent->BindAxis("Turning", this, &AdoomPlayer::Turn);
	PlayerInputComponent->BindAxis("Pitch", this, &AdoomPlayer::Pitch);

}

