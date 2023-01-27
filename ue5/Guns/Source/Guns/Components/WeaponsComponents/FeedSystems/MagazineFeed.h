// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WeaponsComponents/BaseWeaponFeedComponent.h"
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

private:
	FTimerHandle ReloadTimer;

	int32 CurrentAmmo;

};
