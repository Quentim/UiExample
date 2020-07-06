#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SortingMethod.generated.h"

UENUM(BlueprintType)
enum class ESortingMethod : uint8
{
	ByName,
	ByRarity,
	ByValue,
	Unsorted
};

UCLASS()
class UIEXAMPLE_API USortingMethodFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	static FText ToText(ESortingMethod Method)
	{	
		
		switch (Method)
		{
		case ESortingMethod::ByValue:
			return FText::FromString("Value");

		case ESortingMethod::ByName:
			return FText::FromString("Name");

		case ESortingMethod::ByRarity:
			return FText::FromString("Rarity");

		case ESortingMethod::Unsorted:
			return FText::FromString("Unsorted");
		}

		return FText::FromString("Undefined");
	}
};