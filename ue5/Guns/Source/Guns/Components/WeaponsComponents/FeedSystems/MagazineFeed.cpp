// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponsComponents/FeedSystems/MagazineFeed.h"

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
	return  (CurrentAmmo > 0 || GetWorld()->GetTimerManager().IsTimerActive(ReloadTimer));
}

void UMagazineFeed::ConsumeAmmo()
{
	CurrentAmmo -= AmmoPerShot;
}
