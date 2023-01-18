// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponsComponents/TriggerGroups/FullAutoTriggerGroup.h"

UFullAutoTriggerGroup::UFullAutoTriggerGroup()
{
}

void UFullAutoTriggerGroup::StartFire()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(ShotDelayTimer))
	{
		return;
	}
	
	bIsFiring = true;
	
	TriggerGoesOff();
}

void UFullAutoTriggerGroup::StopFire()
{
	bIsFiring = false;
	
	Super::StopFire();
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
	FireDelay = 60 / RateOfFire;
#endif

	GetWorld()->GetTimerManager().SetTimer(ShotDelayTimer, this, &UFullAutoTriggerGroup::TriggerGoesOff,FireDelay, false);
}
