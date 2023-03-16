// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectiles/GBaseProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


AGBaseProjectile::AGBaseProjectile()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(1.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Block);
	CollisionComponent->SetUseCCD(true);
	SetRootComponent(CollisionComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 1000.0f;	
}

void AGBaseProjectile::Launch(FVector Direction)
{
	CollisionComponent->IgnoreActorWhenMoving(GetOwner(), true);
	ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
}

void AGBaseProjectile::Activate(bool bInActive)
{
	bIsActive = bInActive;
	CollisionComponent->SetActive(bInActive);
	ProjectileMovementComponent->SetActive(bInActive);
}

void AGBaseProjectile::SetDelayedExpiredCall(float Delay)
{
	GetWorld()->GetTimerManager().SetTimer(ExpiredTimer, FTimerDelegate::CreateLambda([&]
	{
		OnLifespanExpired.ExecuteIfBound(this);
	}), Delay, false);
}

void AGBaseProjectile::ResetExpiredTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(ExpiredTimer);
}

void AGBaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionComponent->OnComponentHit.AddDynamic(this, &AGBaseProjectile::OnCollisionHit);
}

void AGBaseProjectile::OnCollisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OnProjectileHit.IsBound())
	{
		OnProjectileHit.Broadcast(this, Hit, ProjectileMovementComponent->Velocity.GetSafeNormal());
	}
}
