// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Components/BaseWeaponTriggerGroupComponent.h"
#include "FullAutoTriggerGroup.generated.h"

/**
 * 
 */
UCLASS()
class GUNS_API UFullAutoTriggerGroup : public UBaseWeaponTriggerGroupComponent
{
	GENERATED_BODY()

public:
	UFullAutoTriggerGroup();

	virtual void StartFire() override;
	virtual void StopFire() override;

private:
	void TriggerGoesOff();
	
	bool bIsFiring = false;

	FTimerHandle ShotDelayTimer;
	
};
