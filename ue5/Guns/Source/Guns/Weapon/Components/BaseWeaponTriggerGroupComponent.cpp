// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/BaseWeaponTriggerGroupComponent.h"

UBaseWeaponTriggerGroupComponent::UBaseWeaponTriggerGroupComponent()
{	
}

void UBaseWeaponTriggerGroupComponent::BeginPlay()
{
	Super::BeginPlay();

	FireDelay = 60.0f / RateOfFire;
}

void UBaseWeaponTriggerGroupComponent::StartFire()
{
}

void UBaseWeaponTriggerGroupComponent::StopFire()
{
}

void UBaseWeaponTriggerGroupComponent::InjectSettings(int32 InRateOfFire)
{
	RateOfFire = InRateOfFire;
	FireDelay = 60.0f / RateOfFire;
}
