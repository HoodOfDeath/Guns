// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Components/BaseWeaponTriggerGroupComponent.h"
#include "SemiAutoTriggerGroup.generated.h"

/**
 * 
 */
UCLASS()
class GUNS_API USemiAutoTriggerGroup : public UBaseWeaponTriggerGroupComponent
{
	GENERATED_BODY()

public:

	USemiAutoTriggerGroup();

	virtual void StartFire() override;
	virtual void StopFire() override;

private:

	bool bIsReset = true;

	FTimerHandle ShotDelayTimer;
	
};
