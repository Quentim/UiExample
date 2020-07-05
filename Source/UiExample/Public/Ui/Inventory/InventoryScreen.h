#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/InventoryItemData.h"
#include "InventoryScreen.generated.h"

class UInventoryScreenModel;
class UInventoryScreenList;
class UInventoryScreenSortingPanel;

UCLASS()
class UIEXAMPLE_API UInventoryScreen : public UUserWidget
{
	GENERATED_BODY()

public:

	void InitWithModel(UInventoryScreenModel* InModel);

protected:

	UPROPERTY()
	UInventoryScreenModel* Model = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UInventoryScreenList* InventoryList = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UInventoryScreenSortingPanel* SortingPanel = nullptr;

private:

	void ResetScreen();

	void SortInventoryItems(TArray<FInventoryItemData>& InventoryItems);
	
};


