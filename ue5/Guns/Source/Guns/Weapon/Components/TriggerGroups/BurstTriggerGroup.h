// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Components/BaseWeaponTriggerGroupComponent.h"
#include "BurstTriggerGroup.generated.h"

/**
 * 
 */
UCLASS()
class GUNS_API UBurstTriggerGroup : public UBaseWeaponTriggerGroupComponent
{
	GENERATED_BODY()

public:
	UBurstTriggerGroup();

	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 BurstMaxLength = 3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsInterruptable = true;
	
private:
	void TriggerGoesOff();

	bool bIsFiring = false;

	int32 BurstCounter = 0;

	FTimerHandle ShotDelayTimer;
	
};
