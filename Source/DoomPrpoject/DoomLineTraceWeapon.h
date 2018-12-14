// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoomWeapon.h"
#include "DoomLineTraceWeapon.generated.h"

/**
 * 
 */
UCLASS()
class DOOMPRPOJECT_API ADoomLineTraceWeapon : public ADoomWeapon
{
	GENERATED_BODY()
public:

	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "Weapon Settings")
		float weaponRange = 500.0f;

protected:
	void OnWeaponShoot() override;
	
};
