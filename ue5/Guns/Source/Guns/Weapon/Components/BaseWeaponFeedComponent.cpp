// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/BaseWeaponFeedComponent.h"

UBaseWeaponFeedComponent::UBaseWeaponFeedComponent()
{
}

void UBaseWeaponFeedComponent::InjectSettings(int32 InMaxMagazineAmmo, int32 InAmmoPerShot, EAmmoType InAmmoType)
{
	MaxMagazineAmmo = InMaxMagazineAmmo;
	AmmoPerShot = InAmmoPerShot;
	AmmoType = InAmmoType;
}
