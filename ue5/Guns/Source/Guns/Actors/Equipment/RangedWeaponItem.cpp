// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Equipment/RangedWeaponItem.h"

#include "Components/WeaponsComponents/BaseWeaponBarrelComponent.h"
#include "Components/WeaponsComponents/BaseWeaponFeedComponent.h"
#include "Components/WeaponsComponents/BaseWeaponTriggerGroupComponent.h"

ARangedWeaponItem::ARangedWeaponItem()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponFeed = CreateDefaultSubobject<UBaseWeaponFeedComponent>("WeaponFeed");
	
}

void ARangedWeaponItem::BeginPlay()
{
	Super::BeginPlay();

	checkf(TriggerGroupClass.Get(), TEXT("ARangedWeaponItem::BeginPlay TriggerGroupClass have not been set"))
	
	TriggerGroup = NewObject<UBaseWeaponTriggerGroupComponent>(this, TriggerGroupClass, FName("TriggerGroup"));
	TriggerGroup->RegisterComponent();

	TriggerGroup->OnTriggerGoesOff.AddUObject(this, &ARangedWeaponItem::TriggerGoesOff);

	checkf(WeaponBarrelClass.Get(), TEXT("ARangedWeaponItem::BeginPlay TriggerGroupClass have not been set"))
	
	WeaponBarrel = NewObject<UBaseWeaponBarrelComponent>(this, WeaponBarrelClass, FName("WeaponBarrel"));
	WeaponBarrel->SetupAttachment(WeaponMesh);
	WeaponBarrel->RegisterComponent();
	WeaponBarrel->SetRelativeTransform(BarrelSpawnTransform);

}

void ARangedWeaponItem::BeginDestroy()
{
	Super::BeginDestroy();
}

void ARangedWeaponItem::StartFire()
{
	TriggerGroup->StartFire();
}

void ARangedWeaponItem::StopFire()
{
	TriggerGroup->StopFire();
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

void ARangedWeaponItem::TriggerGoesOff()
{
	if (!WeaponFeed->CanShoot())
	{
		return;
	}

	FVector ShotStartPosition = WeaponBarrel->GetComponentLocation();
	FVector ShotDirection = WeaponBarrel->GetComponentRotation().Vector();
	WeaponBarrel->Shot(ShotStartPosition, ShotDirection);
	WeaponFeed->ConsumeAmmo();
}
