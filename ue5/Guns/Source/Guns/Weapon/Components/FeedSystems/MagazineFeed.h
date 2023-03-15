// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Components/BaseWeaponFeedComponent.h"
#include "MagazineFeed.generated.h"

/**
 * 
 */
UCLASS()
class GUNS_API UMagazineFeed : public UBaseWeaponFeedComponent
{
	GENERATED_BODY()

public:
	UMagazineFeed();

	virtual void BeginPlay() override;

	virtual bool CanShoot() override;

	virtual void ConsumeAmmo() override;

	virtual void Reload() override;

	virtual void InjectSettings(int32 InMaxMagazineAmmo, int32 InAmmoPerShot, EAmmoType InAmmoType) override;

private:
	FTimerHandle ReloadTimer;

	int32 CurrentAmmo;

};
