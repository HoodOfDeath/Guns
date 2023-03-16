// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Components/BaseWeaponBarrelComponent.h"

UBaseWeaponBarrelComponent::UBaseWeaponBarrelComponent()
{
}

void UBaseWeaponBarrelComponent::Shoot(FVector ShotStart, FVector ShotDirection)
{
	DrawDebugLine(GetWorld(), ShotStart, ShotStart + ShotDirection*1000, FColor::Red, false, 2, 0 , 1);
}

void UBaseWeaponBarrelComponent::InjectSettings(float InDamageAmount, TSubclassOf<UDamageType> InDamageTypeClass)
{
	DamageAmount = InDamageAmount;
	DamageTypeClass = InDamageTypeClass;
}

void UBaseWeaponBarrelComponent::ProcessHit(const FHitResult& HitResult, const FVector& Direction)
{
	AActor* HitActor = HitResult.GetActor();
	FPointDamageEvent DamageEvent;
	DamageEvent.HitInfo = HitResult;
	DamageEvent.ShotDirection = Direction;
	DamageEvent.DamageTypeClass = DamageTypeClass;
	HitActor->TakeDamage(DamageAmount, DamageEvent, GetController(), GetOwner());
}

APawn* UBaseWeaponBarrelComponent::GetOwningPawn() const
{
	APawn* OwningPawn = Cast<APawn>(GetOwner()->GetOwner());
	return OwningPawn;
}

AController* UBaseWeaponBarrelComponent::GetController() const
{
	AController* Controller = nullptr;
	APawn* OwningPawn = GetOwningPawn();
	if (IsValid(OwningPawn))
	{
		Controller = OwningPawn->GetController();
	}
	return Controller;
}

