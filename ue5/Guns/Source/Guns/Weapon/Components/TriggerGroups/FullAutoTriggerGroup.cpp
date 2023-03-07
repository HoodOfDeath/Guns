// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/TriggerGroups/FullAutoTriggerGroup.h"

UFullAutoTriggerGroup::UFullAutoTriggerGroup()
{
}

void UFullAutoTriggerGroup::StartFire()
{
	bIsFiring = true;
	
	if (GetWorld()->GetTimerManager().IsTimerActive(ShotDelayTimer))
	{
		return;
	}
	
	TriggerGoesOff();
}

void UFullAutoTriggerGroup::StopFire()
{
	bIsFiring = false;
}

void UFullAutoTriggerGroup::TriggerGoesOff()
{
	if (!bIsFiring)
	{
		return;
	}

	if (OnTriggerGoesOff.IsBound())
	{
		OnTriggerGoesOff.Broadcast();
	}

#if WITH_EDITOR
	FireDelay = 60.0f / RateOfFire;
#endif

	GetWorld()->GetTimerManager().SetTimer(ShotDelayTimer, this, &UFullAutoTriggerGroup::TriggerGoesOff,FireDelay, false);
}
