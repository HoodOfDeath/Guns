// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GBaseCharacter.h"
#include "Components/ActorComponent.h"
#include "CharacterEquipmentComponent.generated.h"

class AEquipableItem;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUNS_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCharacterEquipmentComponent();

	AEquipableItem* GetCurrentEquippedItem() const;

protected:
	TWeakObjectPtr<AEquipableItem> CurrentEquippedItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AEquipableItem> DefaultItemClass;

	virtual void BeginPlay() override;

	void CreateLoadout();

private:
	TWeakObjectPtr<class AGBaseCharacter> CachedBaseCharacter;
};
