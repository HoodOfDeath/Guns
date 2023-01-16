// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseWeaponFeedComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNS_API UBaseWeaponFeedComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBaseWeaponFeedComponent();
		
};
