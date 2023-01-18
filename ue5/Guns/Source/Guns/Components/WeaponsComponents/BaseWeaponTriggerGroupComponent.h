// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseWeaponTriggerGroupComponent.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnTriggerGoesOff)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNS_API UBaseWeaponTriggerGroupComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBaseWeaponTriggerGroupComponent();

	virtual void BeginPlay() override;

	virtual void StartFire();
	virtual void StopFire();

	FOnTriggerGoesOff OnTriggerGoesOff;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(ToolTip="In rounds per minute"))
	float RateOfFire = 500;

	float FireDelay;
	
};
