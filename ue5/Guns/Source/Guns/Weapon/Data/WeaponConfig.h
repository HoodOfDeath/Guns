// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Weapon/Data/WeaponSettings.h"
#include "Weapon/Systems/IWeaponConfigProvider.h"
#include "WeaponConfig.generated.h"

UCLASS()
class GUNS_API UWeaponConfig : public UPrimaryDataAsset, public IWeaponConfigProvider
{
	GENERATED_BODY()

public:
	virtual const FWeaponSettings* GetWeaponSettings() const override { return &WeaponSettings; }

	UPROPERTY(EditDefaultsOnly)
	FWeaponSettings WeaponSettings;
};
