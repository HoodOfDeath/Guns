// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponsComponents/BaseWeaponBarrelComponent.h"

UBaseWeaponBarrelComponent::UBaseWeaponBarrelComponent()
{
}

void UBaseWeaponBarrelComponent::Shot(FVector ShotStart, FVector ShotDirection)
{
	DrawDebugLine(GetWorld(), ShotStart, ShotStart + ShotDirection*1000, FColor::Red, false, 2, 0 , 1);
}

