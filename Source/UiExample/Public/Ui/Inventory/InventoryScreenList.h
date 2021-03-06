#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/InventoryItemData.h"
#include "InventoryScreenList.generated.h"

class UInventoryScreenItem;
class UWrapBox;
class UWrapBoxSlot;



UCLASS()
class UIEXAMPLE_API UInventoryScreenList : public UUserWidget
{
	DECLARE_MULTICAST_DELEGATE_OneParam(FInventoryDataDelegate, FInventoryItemData);
	
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetItems(TArray<FInventoryItemData> InInventoryItems);

	UFUNCTION(BlueprintCallable)
	void SelectItem(FInventoryItemData InItem); 

	UFUNCTION(BlueprintPure)
	FInventoryItemData GetSelectedData() const;

	UFUNCTION(BlueprintPure)
	bool IsItemSelected() const;

	FInventoryDataDelegate OnItemSelected;

protected:
	
	UFUNCTION(BlueprintCallable)
	void RefreshList();

	UFUNCTION(BlueprintImplementableEvent)
	void SetItemStyle(UWrapBoxSlot* Item);
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<FInventoryItemData> InventoryItems;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<UInventoryScreenItem> ListItemClass;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UWrapBox* ItemsBox = nullptr;

private:	

	TArray<UInventoryScreenItem*> ListItems;

	UPROPERTY()
	FInventoryItemData SeletedItemData;
};