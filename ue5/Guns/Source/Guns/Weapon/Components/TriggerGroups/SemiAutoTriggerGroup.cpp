// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/TriggerGroups/SemiAutoTriggerGroup.h"

USemiAutoTriggerGroup::USemiAutoTriggerGroup()
{
}

void USemiAutoTriggerGroup::StartFire()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(ShotDelayTimer) || !bIsReset)
	{
		return;
	}
	
	if (OnTriggerGoesOff.IsBound())
	{
		OnTriggerGoesOff.Broadcast();
	}

	bIsReset = false;
	
	GetWorld()->GetTimerManager().SetTimer(ShotDelayTimer, FireDelay,false);
}

void USemiAutoTriggerGroup::StopFire()
{
	bIsReset = true;
}
