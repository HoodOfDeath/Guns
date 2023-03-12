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

	void InjectSettings(TSubclassOf<AGBaseProjectile> InProjectileClass);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AGBaseProjectile> ProjectileClass;

	UFUNCTION()
	void ProcessProjectileHit(const FHitResult& HitResult, const FVector& Direction);
	
};
