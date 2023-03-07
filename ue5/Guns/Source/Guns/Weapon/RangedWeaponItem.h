// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Equipment/EquipableItem.h"
#include "RangedWeaponItem.generated.h"

class USkeletalMeshComponent;
class UBaseWeaponBarrelComponent;
class UBaseWeaponFeedComponent;
class UBaseWeaponTriggerGroupComponent;

UCLASS()
class GUNS_API ARangedWeaponItem : public AEquipableItem
{
	GENERATED_BODY()
	
public:
	ARangedWeaponItem();

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	void StartFire();
	void StopFire();
	
	void StartAiming();
	void StopAiming();

	void Reload();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBaseWeaponBarrelComponent* WeaponBarrel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBaseWeaponBarrelComponent> WeaponBarrelClass;

	UPROPERTY(EditAnywhere, meta=(MakeEditWidget = true))
	FTransform BarrelSpawnTransform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBaseWeaponFeedComponent* WeaponFeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBaseWeaponFeedComponent> WeaponFeedClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBaseWeaponTriggerGroupComponent* TriggerGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBaseWeaponTriggerGroupComponent> TriggerGroupClass;

	void TriggerGoesOff();
};
