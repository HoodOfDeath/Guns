// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponsComponents/TriggerGroups/BurstTriggerGroup.h"

UBurstTriggerGroup::UBurstTriggerGroup()
{
}

void UBurstTriggerGroup::StartFire()
{
	bIsFiring = true;
	
	if (GetWorld()->GetTimerManager().IsTimerActive(ShotDelayTimer))
	{
		return;
	}
	
	TriggerGoesOff();
}

void UBurstTriggerGroup::StopFire()
{
	bIsFiring = false;
}

void UBurstTriggerGroup::TriggerGoesOff()
{
	if (BurstCounter >= BurstMaxLength)
	{
		BurstCounter = 0;
		StopFire();
		return;
	}

	if (bIsInterruptable && !bIsFiring)
    {
    	return;
    }

	if (OnTriggerGoesOff.IsBound())
	{
		OnTriggerGoesOff.Broadcast();
	}

	++BurstCounter;

#if WITH_EDITOR
	FireDelay = 60.0f / RateOfFire;
#endif

	GetWorld()->GetTimerManager().SetTimer(ShotDelayTimer, this, &UBurstTriggerGroup::TriggerGoesOff,FireDelay, false);
}
