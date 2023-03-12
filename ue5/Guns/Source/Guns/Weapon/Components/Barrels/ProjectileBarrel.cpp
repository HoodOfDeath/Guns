// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/Barrels/ProjectileBarrel.h"

#include "Actors/Projectiles/GBaseProjectile.h"

UProjectileBarrel::UProjectileBarrel()
{
}

void UProjectileBarrel::Shoot(FVector ShotStart, FVector ShotDirection)
{
	checkf(ProjectileClass.Get(), TEXT("UProjectileBarrel::Shot Projectile class is invalid"))

	AGBaseProjectile* NewProjectile = GetWorld()->SpawnActor<AGBaseProjectile>(ProjectileClass, ShotStart, ShotDirection.Rotation());
	NewProjectile->SetLifeSpan(5.0f);
	NewProjectile->OnProjectileHit.AddDynamic(this, &UProjectileBarrel::ProcessProjectileHit);
}

void UProjectileBarrel::InjectSettings(TSubclassOf<AGBaseProjectile> InProjectileClass)
{
	ProjectileClass = InProjectileClass;
}

void UProjectileBarrel::ProcessProjectileHit(const FHitResult& HitResult, const FVector& Direction)
{
	ProcessHit(HitResult, Direction);
}
