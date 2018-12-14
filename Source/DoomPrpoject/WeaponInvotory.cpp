// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponInvotory.h"
#include "Engine/World.h"
#include "DoomWeapon.h"

// Sets default values for this component's properties
UWeaponInvotory::UWeaponInvotory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


bool UWeaponInvotory::FireCurrentWeapon()
{
	return currentWeapon->Shoot();
}

bool UWeaponInvotory::SwitchWeapon()
{

	if (weaponIndex >= 0)
		weapons[weaponIndex]->SetActorHiddenInGame(true);

	weaponIndex++;

	if (weaponIndex >= weapons.Num())
		weaponIndex = 0;

	currentWeapon = weapons[weaponIndex];

	if (!currentWeapon) return false;

	currentWeapon->AddActorLocalOffset(FVector(-25, 0, -25));

	currentWeapon->SetActorHiddenInGame(false);

	return true;
}

bool UWeaponInvotory::CanSwitchWeapon()
{

	if (weapons.Num() <= 1) return false;

	return true;
}

ADoomWeapon * UWeaponInvotory::GetCurrentWeapon()
{
	return currentWeapon;
}

// Called when the game starts
void UWeaponInvotory::BeginPlay()
{
	Super::BeginPlay();

	InitWeapon();
	
}


// Called every frame
void UWeaponInvotory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!currentWeapon) return;

	FVector v = FMath::Lerp(v, GetOwner()->GetActorLocation(), 10.f * DeltaTime);

	currentWeapon->SetActorLocation(v);

}

void UWeaponInvotory::InitWeapon()
{

	for (int i = 0; i < startingWeapon.Num(); i++)
	{

		ADoomWeapon * weapon = GetWorld()->SpawnActor<ADoomWeapon>(
			startingWeapon[i], GetOwner()->GetActorLocation(), FRotator::ZeroRotator
		);

		if (!weapon) continue;

		weapon->AttachToComponent(
			GetOwner()->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale
		);

		weapon->SetActorHiddenInGame(true);

		weapons.Add(weapon);

		if (weapons.Num() <= 0) return;

		weaponIndex = -1;

		SwitchWeapon();


	}


}

bool UWeaponInvotory::CanShoot()
{
	return false;
}

