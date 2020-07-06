#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/InventoryItemData.h"
#include "Ui/SortingMethod.h"
#include "InventoryScreen.generated.h"


class UInventoryItemDetails;
class UInventoryScreenModel;
class UInventoryScreenList;
class UInventoryScreenSortingPanel;

UCLASS()
class UIEXAMPLE_API UInventoryScreen : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void InitWithModel(UInventoryScreenModel* InModel);

	UFUNCTION(BlueprintCallable)
	void ResetList();

protected:

	UPROPERTY()
	UInventoryScreenModel* Model = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	ESortingMethod DefaultSortingMethod = ESortingMethod::Unsorted;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UInventoryScreenList* InventoryList = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UInventoryItemDetails* Details = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UInventoryScreenSortingPanel* SortingPanel = nullptr;

private:

	void SortInventoryItems(TArray<FInventoryItemData>& InventoryItems);
	
};


