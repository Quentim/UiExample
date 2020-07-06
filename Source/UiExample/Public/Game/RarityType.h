#pragma once
#include "CoreMinimal.h"
#include "RarityType.generated.h"


UENUM(BlueprintType)
enum class ERarityType : uint8
{
	NonRarity,
	Common,
	Rare,
	Epic,
	Legendary,
	Unknown
}; 