#pragma once

#include "CoreMinimal.h"
#include "RarityType.h"
#include "InventoryItemData.generated.h"


class UTexture2D;

USTRUCT(BlueprintType)
struct UIEXAMPLE_API FInventoryItemData
{
	GENERATED_BODY()

	bool operator==(const FInventoryItemData& Other)
	{
		return this->Id == Other.Id;
	}

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Id = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERarityType	Rarity = ERarityType::Unknown;

};
