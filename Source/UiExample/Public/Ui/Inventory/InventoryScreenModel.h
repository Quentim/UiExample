#pragma once

#include "CoreMinimal.h"
#include "Game/InventoryItemData.h"
#include "UObject/NoExportTypes.h"
#include "InventoryScreenModel.generated.h"
 

UCLASS(BlueprintType, Blueprintable, Abstract)
class UIEXAMPLE_API UInventoryScreenModel : public UObject
{
	GENERATED_BODY()

public:

	// Native Event poniewaz chce stworzyc mocka tego Modelu w blueprincie	
	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	TArray<FInventoryItemData> GetInventoryItems();

	FSimpleMulticastDelegate OnInventoryItemsChanged;	
	
};
