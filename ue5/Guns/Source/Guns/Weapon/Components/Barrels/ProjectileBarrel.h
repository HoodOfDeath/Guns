// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Components/BaseWeaponBarrelComponent.h"
#include "ProjectileBarrel.generated.h"

class AGBaseProjectile;

UCLASS()
class GUNS_API UProjectileBarrel : public UBaseWeaponBarrelComponent
{
	GENERATED_BODY()

public:
	UProjectileBarrel();
	
	virtual void Shoot(FVector ShotStart, FVector ShotDirection) override;

	void InjectSettings(TSubclassOf<AGBaseProjectile> InProjectileClass, int32 InProjectilePoolSize, float InProjectileLifespan);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AGBaseProjectile> ProjectileClass;

	UFUNCTION()
	void ProcessProjectileHit(AGBaseProjectile* Projectile, const FHitResult& HitResult, const FVector& Direction);

	UFUNCTION()
	void ReturnProjectileToPool(AGBaseProjectile* Projectile);

private:
	const FVector POOL_LOCATION {0,0,-1000000};

	int32 ProjectilePoolSize = 30;

	float ProjectileLifespan = 5.0f;

	int32 CurrentPoolIndex = 0;
	
	TArray<AGBaseProjectile*> ProjectilePool;
	
	void InitProjectilePool();
	
	AGBaseProjectile* GetNextAvailableProjectile();
	
};
