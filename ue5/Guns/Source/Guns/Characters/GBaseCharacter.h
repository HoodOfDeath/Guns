// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GBaseCharacter.generated.h"

class UCharacterEquipmentComponent;

UCLASS(Abstract, NotBlueprintable)
class GUNS_API AGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGBaseCharacter();

	virtual void BeginPlay() override;

	virtual USkeletalMeshComponent* GetMeshForItemAttachment() const;
	
	virtual void MoveForward(float Value) {};
	virtual void MoveRight(float Value) {};
	virtual void Turn(float Value) {};
	virtual void LookUp(float Value) {};
	virtual void TurnAtRate(float Value) {};
	virtual void LookUpAtRate(float Value) {};

	void StartFire();
	void StopFire();

	void StartAiming();
	void StopAiming();

	void Reload();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCharacterEquipmentComponent* CharacterEquipmentComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UHealthComponent* HealthComponent;
	
};
