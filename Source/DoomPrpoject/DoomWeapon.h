// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoomWeapon.generated.h"

class UStaticMeshoComponent;	//	decalirs static mesh
class UPointLightComponent;		//	declair point light 


UCLASS()
class DOOMPRPOJECT_API ADoomWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoomWeapon();

	UPROPERTY(Category = "Doom Character", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* weaponMesh;

	UPROPERTY(Category = "Doom Character", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UPointLightComponent* weaponLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "Weapon Settings", EditAnywhere, BlueprintReadWrite)
		float rateOfFire = 1;

	UPROPERTY(Category = "Weapon Settings", EditAnywhere, BlueprintReadWrite)
		float maxAmmo = 100;

	UPROPERTY(Category = "Weapon Settings", EditAnywhere, BlueprintReadWrite)
		float currentAmmo = 100;

	UPROPERTY(Category = "Weapon Settings", EditAnywhere, BlueprintReadWrite)
		float isSemiAuto = false;

protected:
	virtual void OnWeaponShoot();

private:
	float nextFire = -1;

public:
	bool Shoot();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Weapon Shoot"))
		void BPEVENT_OnWeaponShoot();


	
};
