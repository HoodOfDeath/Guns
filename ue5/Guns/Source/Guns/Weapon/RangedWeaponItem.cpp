// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/RangedWeaponItem.h"

#include "Weapon/Components/Barrels/ProjectileBarrel.h"
#include "Weapon/Components/BaseWeaponBarrelComponent.h"
#include "Weapon/Components/BaseWeaponFeedComponent.h"
#include "Weapon/Components/BaseWeaponTriggerGroupComponent.h"

ARangedWeaponItem::ARangedWeaponItem()
{
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
}

void ARangedWeaponItem::BeginPlay()
{
	Super::BeginPlay();

	if (WeaponConfigProvider.GetInterface() != nullptr)
	{
		const FWeaponSettings* Settings = WeaponConfigProvider->GetWeaponSettings();
		
		checkf(Settings->TriggerGroupClass.Get(), TEXT("ARangedWeaponItem::BeginPlay TriggerGroupClass have not been set in WeaponConfigProvider"))
		TriggerGroup = NewObject<UBaseWeaponTriggerGroupComponent>(this, Settings->TriggerGroupClass, FName("TriggerGroup"));
		TriggerGroup->RegisterComponent();
		TriggerGroup->OnTriggerGoesOff.AddUObject(this, &ARangedWeaponItem::TriggerGoesOff);
		
		TriggerGroup->InjectSettings(Settings->RateOfFire);

		checkf(Settings->WeaponFeedClass.Get(), TEXT("ARangedWeaponItem::BeginPlay WeaponFeedClass have not been set in WeaponConfigProvider"))
	
		WeaponFeed = NewObject<UBaseWeaponFeedComponent>(this, Settings->WeaponFeedClass, FName("WeaponFeed"));
		WeaponFeed->RegisterComponent();

		WeaponFeed->InjectSettings(Settings->MaxMagazineAmmo, Settings->AmmoPerShot, Settings->AmmoType);

		checkf(Settings->WeaponBarrelClass.Get(), TEXT("ARangedWeaponItem::BeginPlay TriggerGroupClass have not been set in WeaponConfigProvider"))
	
		WeaponBarrel = NewObject<UBaseWeaponBarrelComponent>(this, Settings->WeaponBarrelClass, FName("WeaponBarrel"));
		WeaponBarrel->SetupAttachment(WeaponMesh);
		WeaponBarrel->RegisterComponent();
		WeaponBarrel->SetRelativeTransform(BarrelSpawnTransform);

		if (UProjectileBarrel* ProjectileBarrel = Cast<UProjectileBarrel>(WeaponBarrel))
		{
			ProjectileBarrel->InjectSettings(Settings->ProjectileClass);
		}

		WeaponBarrel->InjectSettings(Settings->DamageAmount, Settings->DamageTypeClass);
	}
	else
	{
		checkf(TriggerGroupClass.Get(), TEXT("ARangedWeaponItem::BeginPlay TriggerGroupClass have not been set"))

		TriggerGroup = NewObject<UBaseWeaponTriggerGroupComponent>(this, TriggerGroupClass, FName("TriggerGroup"));
		TriggerGroup->RegisterComponent();
		TriggerGroup->OnTriggerGoesOff.AddUObject(this, &ARangedWeaponItem::TriggerGoesOff);

		checkf(WeaponFeedClass.Get(), TEXT("ARangedWeaponItem::BeginPlay WeaponFeedClass have not been set"))
	
		WeaponFeed = NewObject<UBaseWeaponFeedComponent>(this, WeaponFeedClass, FName("WeaponFeed"));
		WeaponFeed->RegisterComponent();

		checkf(WeaponBarrelClass.Get(), TEXT("ARangedWeaponItem::BeginPlay TriggerGroupClass have not been set"))
	
		WeaponBarrel = NewObject<UBaseWeaponBarrelComponent>(this, WeaponBarrelClass, FName("WeaponBarrel"));
		WeaponBarrel->SetupAttachment(WeaponMesh);
		WeaponBarrel->RegisterComponent();
		WeaponBarrel->SetRelativeTransform(BarrelSpawnTransform);
	}

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
	WeaponFeed->Reload();
}

void ARangedWeaponItem::TriggerGoesOff()
{
	if (!WeaponFeed->CanShoot())
	{
		return;
	}

	FVector ShotStartPosition = WeaponBarrel->GetComponentLocation();
	FVector ShotDirection = WeaponBarrel->GetComponentRotation().Vector();
	WeaponBarrel->Shoot(ShotStartPosition, ShotDirection);
	WeaponFeed->ConsumeAmmo();
}
