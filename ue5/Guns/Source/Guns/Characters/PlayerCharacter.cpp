// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"

#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter()
{
	CameraComponentFirstPerson = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponentFirstPerson->SetupAttachment(RootComponent);
	CameraComponentFirstPerson->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
	CameraComponentFirstPerson->bUsePawnControlRotation = true;

	MeshFirstPerson = CreateDefaultSubobject<USkeletalMeshComponent>("MeshFirstPerson");
	MeshFirstPerson->SetupAttachment(CameraComponentFirstPerson);
	MeshFirstPerson->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	MeshFirstPerson->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
	
}

USkeletalMeshComponent* APlayerCharacter::GetMeshForItemAttachment() const
{
	return MeshFirstPerson;
}

void APlayerCharacter::MoveForward(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(GetActorForwardVector(), Value);
		/* TODO: test difference between implementations 
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, Value);
		*/
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::TurnAtRate(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerCharacter::LookUpAtRate(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent)

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	
	PlayerInputComponent->BindAxis("TurnAtRate", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpAtRate", this, &APlayerCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAction("PrimaryAction",IE_Pressed, this, &APlayerCharacter::StartFire);
	PlayerInputComponent->BindAction("PrimaryAction",IE_Released, this, &APlayerCharacter::StopFire);
	
}
