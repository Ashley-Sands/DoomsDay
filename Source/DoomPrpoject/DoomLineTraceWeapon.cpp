// Fill out your copyright notice in the Description page of Project Settings.

#include "DoomLineTraceWeapon.h"
#include "Engine/world.h"
#include "Engine.h"

void ADoomLineTraceWeapon::OnWeaponShoot()
{

	FHitResult hit;
	FCollisionQueryParams parmams = FCollisionQueryParams(FName(), true);

	FVector start = GetActorLocation();
	FVector end = start + (GetActorForwardVector() * weaponRange);

	if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECollisionChannel::ECC_Visibility, parmams))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, hit.GetActor()->GetName());
	}

}
