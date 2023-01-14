// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GBaseCharacter.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;

UCLASS(Blueprintable)
class GUNS_API APlayerCharacter : public AGBaseCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	virtual USkeletalMeshComponent* GetMeshForItemAttachment() const override;

	virtual void MoveForward(float Value) override;
	virtual void MoveRight(float Value) override;
	virtual void Turn(float Value) override;
	virtual void LookUp(float Value) override;
	virtual void TurnAtRate(float Value) override;
	virtual void LookUpAtRate(float Value) override;

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character | Controls")
	float BaseTurnRate = 45.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character | Controls")
	float BaseLookUpRate = 45.0f;

private:
	UPROPERTY(VisibleDefaultsOnly, Category="Character | Mesh")
	USkeletalMeshComponent* MeshFirstPerson;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="Character | Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponentFirstPerson;
};
