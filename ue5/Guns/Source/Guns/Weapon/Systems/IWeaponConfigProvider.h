#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Weapon/Data/WeaponSettings.h"
#include "IWeaponConfigProvider.generated.h"

UINTERFACE(MinimalAPI)
class UWeaponConfigProvider : public UInterface
{
	GENERATED_BODY()
};

class GUNS_API IWeaponConfigProvider
{
	GENERATED_BODY()
public:

	virtual const FWeaponSettings* GetWeaponSettings() const = 0;
};
