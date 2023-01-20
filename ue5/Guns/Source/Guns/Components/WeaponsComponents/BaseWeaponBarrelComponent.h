// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BaseWeaponBarrelComponent.generated.h"


UCLASS(BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNS_API UBaseWeaponBarrelComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UBaseWeaponBarrelComponent();

	virtual void Shot(FVector ShotStart, FVector ShotDirection);
	
};
