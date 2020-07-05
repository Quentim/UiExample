#pragma once

#include "CoreMinimal.h"
#include "RarityType.generated.h"


UENUM(BlueprintType)
enum class ERarityType : uint8
{
	Common,
	Rare,
	Epic,
	Legendary,
	NonRarity,
	Unknown

};
