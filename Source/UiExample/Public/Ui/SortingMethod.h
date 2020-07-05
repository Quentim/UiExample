#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ESortingMethod : uint8
{
	ByName,
	ByRarity,
	ByValue,
	Unsorted
};