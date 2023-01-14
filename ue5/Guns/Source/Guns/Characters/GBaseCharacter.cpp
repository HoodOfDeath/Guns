// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GBaseCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/CharacterComponents/CharacterEquipmentComponent.h"

AGBaseCharacter::AGBaseCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	CharacterEquipmentComponent = CreateDefaultSubobject<UCharacterEquipmentComponent>(TEXT("CharacterEquipment"));
}

USkeletalMeshComponent* AGBaseCharacter::GetMeshForItemAttachment() const
{
	return GetMesh();
}

void AGBaseCharacter::StartFire()
{
}

void AGBaseCharacter::StopFire()
{
}

void AGBaseCharacter::StartAiming()
{
}

void AGBaseCharacter::StopAiming()
{
}

void AGBaseCharacter::Reload()
{
}
