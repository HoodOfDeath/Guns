// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GBaseCharacter.h"

#include "Weapon/RangedWeaponItem.h"
#include "Components/CapsuleComponent.h"
#include "Components/HealthComponent.h"
#include "Characters/Components/CharacterEquipmentComponent.h"

AGBaseCharacter::AGBaseCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	CharacterEquipmentComponent = CreateDefaultSubobject<UCharacterEquipmentComponent>(TEXT("CharacterEquipment"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void AGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	HealthComponent->OnDeathEvent.AddLambda([]()
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Red, FString("Ughhh... I'm dying"));
		}
	});
}

USkeletalMeshComponent* AGBaseCharacter::GetMeshForItemAttachment() const
{
	return GetMesh();
}

void AGBaseCharacter::StartFire()
{
	ARangedWeaponItem* Weapon = StaticCast<ARangedWeaponItem*>(CharacterEquipmentComponent->GetCurrentEquippedItem());
	Weapon->StartFire();
}

void AGBaseCharacter::StopFire()
{
	ARangedWeaponItem* Weapon = StaticCast<ARangedWeaponItem*>(CharacterEquipmentComponent->GetCurrentEquippedItem());
	Weapon->StopFire();
}

void AGBaseCharacter::StartAiming()
{
}

void AGBaseCharacter::StopAiming()
{
}

void AGBaseCharacter::Reload()
{
	ARangedWeaponItem* Weapon = StaticCast<ARangedWeaponItem*>(CharacterEquipmentComponent->GetCurrentEquippedItem());
	Weapon->Reload();
}
