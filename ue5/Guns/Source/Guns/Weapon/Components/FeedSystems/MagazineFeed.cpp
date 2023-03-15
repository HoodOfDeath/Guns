// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/FeedSystems/MagazineFeed.h"

UMagazineFeed::UMagazineFeed()
{
}

void UMagazineFeed::BeginPlay()
{
	Super::BeginPlay();

	CurrentAmmo = MaxMagazineAmmo;
}

bool UMagazineFeed::CanShoot()
{
	return CurrentAmmo > 0;
}

void UMagazineFeed::ConsumeAmmo()
{
	CurrentAmmo -= AmmoPerShot;
	if (GEngine)
	{
		//TODO Add hud to show ammo count
		FString Message = FString::Printf(TEXT("CurrentAmmo %d"), CurrentAmmo);
		GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Red, *Message);
	}
}

void UMagazineFeed::Reload()
{
	if(GetWorld()->GetTimerManager().IsTimerActive(ReloadTimer))
	{
		return;
	}
	
	//TODO Start animation an get its duration
	const float ReloadTime = 3.0f; 
	
	GetWorld()->GetTimerManager().SetTimer(ReloadTimer, [&](){ CurrentAmmo = MaxMagazineAmmo;}, ReloadTime, false);

	CurrentAmmo = 0;
}

void UMagazineFeed::InjectSettings(int32 InMaxMagazineAmmo, int32 InAmmoPerShot, EAmmoType InAmmoType)
{
	CurrentAmmo = InMaxMagazineAmmo;
	Super::InjectSettings(InMaxMagazineAmmo, InAmmoPerShot, InAmmoType);
}
