// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/Barrels/ProjectileBarrel.h"

#include "Actors/Projectiles/GBaseProjectile.h"

UProjectileBarrel::UProjectileBarrel()
{
}

void UProjectileBarrel::Shoot(FVector ShotStart, FVector ShotDirection)
{
	checkf(ProjectileClass.Get(), TEXT("UProjectileBarrel::Shot Projectile class is invalid"))

	AGBaseProjectile* Projectile = GetNextAvailableProjectile();
	Projectile->SetActorLocationAndRotation(ShotStart,ShotDirection.ToOrientationRotator());
	Projectile->Activate(true);
	Projectile->SetDelayedExpiredCall(ProjectileLifespan);
	Projectile->Launch(ShotDirection);
}

AGBaseProjectile* UProjectileBarrel::GetNextAvailableProjectile()
{
	int32 NumberOfTries = ProjectilePoolSize + 1;
	AGBaseProjectile* Projectile = ProjectilePool[CurrentPoolIndex];

	// loop will go through entire list and one more, to get inactive projectile or longest in used
	for (int i = 0; i < NumberOfTries; ++i)
	{
		++CurrentPoolIndex;
		if (CurrentPoolIndex >= ProjectilePoolSize)
		{
			CurrentPoolIndex = 0;
		}	
		Projectile = ProjectilePool[CurrentPoolIndex];
		if (!Projectile->IsActive())
		{
			break;
		}
	}
	return Projectile;
}

void UProjectileBarrel::InjectSettings(TSubclassOf<AGBaseProjectile> InProjectileClass, int32 InProjectilePoolSize, float InProjectileLifespan)
{
	ProjectileClass = InProjectileClass;
	ProjectilePoolSize = InProjectilePoolSize;
	ProjectileLifespan = InProjectileLifespan;

	InitProjectilePool();
}

void UProjectileBarrel::ProcessProjectileHit(AGBaseProjectile* Projectile, const FHitResult& HitResult, const FVector& Direction)
{
	Projectile->ResetExpiredTimer();
	ReturnProjectileToPool(Projectile);
	
	ProcessHit(HitResult, Direction);
}

void UProjectileBarrel::InitProjectilePool()
{
	checkf(ProjectileClass.Get(), TEXT("UProjectileBarrel::Shot Projectile class is invalid"))
	
	ProjectilePool.Reserve(ProjectilePoolSize);

	APawn* OwningPawn = GetOwningPawn();
	for (int i = 0; i < ProjectilePoolSize; ++i)
	{
		AGBaseProjectile* NewProjectile = GetWorld()->SpawnActor<AGBaseProjectile>(ProjectileClass, POOL_LOCATION, FRotator::ZeroRotator);
		NewProjectile->Activate(false);
		NewProjectile->SetOwner(OwningPawn);
		NewProjectile->OnProjectileHit.AddDynamic(this, &UProjectileBarrel::ProcessProjectileHit);
		NewProjectile->OnLifespanExpired.BindUObject(this, &UProjectileBarrel::ReturnProjectileToPool);
		ProjectilePool.Add(NewProjectile);
	}
}

void UProjectileBarrel::ReturnProjectileToPool(AGBaseProjectile* Projectile)
{
	Projectile->Activate(false);
	Projectile->SetActorLocation(POOL_LOCATION);
}
