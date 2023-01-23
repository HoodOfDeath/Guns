// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GBaseProjectile.generated.h"

UCLASS()
class GUNS_API AGBaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AGBaseProjectile();
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProjectileHit, const FHitResult&, Hit, const FVector&, Direction);
	
	UPROPERTY(BlueprintAssignable)
	FOnProjectileHit OnProjectileHit; 

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;
	
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnCollisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
