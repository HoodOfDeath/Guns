// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponsComponents/Barrels/HitscanBarrel.h"

#include "GunsCommonTypes.h"

UHitscanBarrel::UHitscanBarrel()
{
}

void UHitscanBarrel::Shoot(FVector ShotStart, FVector ShotDirection)
{
	FHitResult HitResult;
	FVector ShotEnd = ShotStart + (ShotDirection * ShotRange);
	if(GetWorld()->LineTraceSingleByChannel(HitResult, ShotStart, ShotEnd, ECC_Bullet))
	{
		ProcessHit(HitResult, ShotDirection);
	}
}
