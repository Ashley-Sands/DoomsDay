// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponInvotory.generated.h"

class ADoomWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DOOMPRPOJECT_API UWeaponInvotory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponInvotory();

	bool FireCurrentWeapon();
	bool SwitchWeapon();
	bool CanSwitchWeapon();

	ADoomWeapon * GetCurrentWeapon();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(Category = "Doom Weapon", EditAnywhere)
		TArray<TSubclassOf<ADoomWeapon>> startingWeapon;

private:
	TArray<ADoomWeapon*> weapons;
	void InitWeapon();
	int weaponIndex = 0;
	ADoomWeapon* currentWeapon;

	bool CanShoot();

};
