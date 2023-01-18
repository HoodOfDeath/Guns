// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterComponents/CharacterEquipmentComponent.h"

#include "Actors/Equipment/EquipableItem.h"
#include "Characters/GBaseCharacter.h"

// Sets default values for this component's properties
UCharacterEquipmentComponent::UCharacterEquipmentComponent()
{
}

AEquipableItem* UCharacterEquipmentComponent::GetCurrentEquippedItem() const
{
	return CurrentEquippedItem.Get();
}

void UCharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	checkf(GetOwner()->IsA<AGBaseCharacter>(), TEXT("UCharacterEquipmentComponent::BeginPlay() CharacterEquipmentComponent can be used only with a GBaseCharacter"));
	CachedBaseCharacter = StaticCast<AGBaseCharacter*>(GetOwner());
	
	CreateLoadout();
}

void UCharacterEquipmentComponent::CreateLoadout()
{
	if (!IsValid(DefaultItemClass))
	{
		UE_LOG(LogTemp, Error, TEXT("UCharacterEquipmentComponent::CreateLoadout DefaultItemClass is not specified"));
		return;
	}

	CurrentEquippedItem = GetWorld()->SpawnActor<AEquipableItem>(DefaultItemClass);
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	CurrentEquippedItem->AttachToComponent(CachedBaseCharacter->GetMeshForItemAttachment(),AttachmentRules, FName(TEXT("GripPoint")));
	CurrentEquippedItem->SetOwner(CachedBaseCharacter.Get());
}

