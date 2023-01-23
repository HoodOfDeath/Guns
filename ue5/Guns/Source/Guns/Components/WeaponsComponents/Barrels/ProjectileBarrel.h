// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WeaponsComponents/BaseWeaponBarrelComponent.h"
#include "ProjectileBarrel.generated.h"

/**
 * 
 */
UCLASS()
class GUNS_API UProjectileBarrel : public UBaseWeaponBarrelComponent
{
	GENERATED_BODY()

public:
	UProjectileBarrel();
	
	virtual void Shot(FVector ShotStart, FVector ShotDirection) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class AGBaseProjectile> ProjectileClass;

	UFUNCTION()
	void ProcessProjectileHit(const FHitResult& HitResult, const FVector& Direction);
	
};
