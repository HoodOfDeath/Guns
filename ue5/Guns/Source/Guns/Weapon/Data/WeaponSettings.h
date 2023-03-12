#pragma once

#include "Weapon/Components/BaseWeaponBarrelComponent.h"
#include "Weapon/Components/BaseWeaponFeedComponent.h"
#include "Weapon/Components/BaseWeaponTriggerGroupComponent.h"
#include "Actors/Projectiles/GBaseProjectile.h"
#include "Enums/EAmmoType.h"

#include "WeaponSettings.generated.h"

USTRUCT(BlueprintType)
struct FWeaponSettings
{
	GENERATED_BODY()

	//
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	TSubclassOf<UBaseWeaponBarrelComponent> WeaponBarrelClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	TSubclassOf<UBaseWeaponFeedComponent> WeaponFeedClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	TSubclassOf<UBaseWeaponTriggerGroupComponent> TriggerGroupClass;

	// Barrel settings
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Barrel", meta = (UIMin = 0.0f, ClampMin = 0.0f))
	float DamageAmount = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Barrel")
	TSubclassOf<UDamageType> DamageTypeClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Barrel")
	TSubclassOf<AGBaseProjectile> ProjectileClass;

	// Trigger settings
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trigger", meta=(ToolTip="In rounds per minute"))
	int32 RateOfFire = 451;

	// Feed settings

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Feed")
	int32 MaxMagazineAmmo = 30;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Feed")
	int32 AmmoPerShot = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Feed")
	EAmmoType AmmoType;

};