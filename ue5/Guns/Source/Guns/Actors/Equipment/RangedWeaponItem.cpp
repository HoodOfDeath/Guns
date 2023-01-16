// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Equipment/RangedWeaponItem.h"

#include "Components/WeaponsComponents/BaseWeaponBarrelComponent.h"
#include "Components/WeaponsComponents/BaseWeaponFeedComponent.h"
#include "Components/WeaponsComponents/BaseWeaponTriggerGroupComponent.h"

ARangedWeaponItem::ARangedWeaponItem()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponBarrel = CreateDefaultSubobject<UBaseWeaponBarrelComponent>("WeaponBarrel");
	WeaponBarrel->SetupAttachment(WeaponMesh);

	WeaponFeed = CreateDefaultSubobject<UBaseWeaponFeedComponent>("WeaponFeed");

	TriggerGroup = CreateDefaultSubobject<UBaseWeaponTriggerGroupComponent>("TriggerGroup");
}

void ARangedWeaponItem::BeginPlay()
{
	Super::BeginPlay();
}

void ARangedWeaponItem::StartFire()
{
}

void ARangedWeaponItem::StopFire()
{
}

void ARangedWeaponItem::StartAiming()
{
}

void ARangedWeaponItem::StopAiming()
{
}

void ARangedWeaponItem::Reload()
{
}
