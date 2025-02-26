// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "doomPlayer.generated.h"

class UCameraComponent;
class UWeaponInvotory;

UCLASS()
class DOOMPRPOJECT_API AdoomPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AdoomPlayer();

	UPROPERTY(Category = "Doom Character", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* camera;

	UPROPERTY(Category = "Doom Character", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UWeaponInvotory* invotory;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float scale);
	void Strafe(float scale);
	void Turn(float scale);
	void Pitch(float scale);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ShootPressAction();
	void ShootReleaseAction();
	void CycleWeaponAction();
	void UpdateShootingAction();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Weapon Shoot"))
		void BPEVENT_OnCurrentWeaponShoot();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Weapon Shoot"))
		void BPEVENT_OnCurrentWeaponSwitched();
	
private:
	bool isShooting = false;

};
