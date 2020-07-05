#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryScreen.generated.h"

class UInventoryScreenList;

UCLASS()
class UIEXAMPLE_API UInventoryScreen : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UInventoryScreenList* InventoryList = nullptr;
	
};
