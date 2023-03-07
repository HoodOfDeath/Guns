// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Components/BaseWeaponBarrelComponent.h"
#include "HitscanBarrel.generated.h"

/**
 * 
 */
UCLASS()
class GUNS_API UHitscanBarrel : public UBaseWeaponBarrelComponent
{
	GENERATED_BODY()

public:
	UHitscanBarrel();

	virtual void Shoot(FVector ShotStart, FVector ShotDirection) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float ShotRange = 5000.0f;
	
};
