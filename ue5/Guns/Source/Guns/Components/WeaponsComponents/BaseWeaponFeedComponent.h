// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums/AmmoType.h"
#include "BaseWeaponFeedComponent.generated.h"


UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNS_API UBaseWeaponFeedComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBaseWeaponFeedComponent();

	virtual bool CanShoot() { return true; }

	virtual void ConsumeAmmo() {};

	virtual void Reload() {};

protected:
	EAmmoType GetAmmoType() const { return AmmoType; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxMagazineAmmo = 30;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 AmmoPerShot = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EAmmoType AmmoType;
};
