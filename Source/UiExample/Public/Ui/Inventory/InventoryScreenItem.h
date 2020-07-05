#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/InventoryItemData.h"
#include "InventoryScreenItem.generated.h"

class UButton;

UCLASS()
class UIEXAMPLE_API UInventoryScreenItem : public UUserWidget
{
	DECLARE_MULTICAST_DELEGATE_OneParam(FInventoryScreenItemDelegate, UInventoryScreenItem*);
		
	GENERATED_BODY()

public:

	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetInventoryItem(FInventoryItemData InData);

	UFUNCTION(BlueprintCallable)
	FInventoryItemData GetSetInventoryItem() const;

	void SetIsSelected(bool InIsSelected);
	
	FInventoryScreenItemDelegate OnClciked;

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetWidget();	

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FInventoryItemData Data;

	UPROPERTY(BlueprintReadOnly)
	bool bIsSelected;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UButton* MainButton = nullptr;


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSelectedStyle();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetRegularStyle();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHoveredStyle();

private:
	
	void OnClickedHandler();
	void OnHoveredHandler();
	void OnUnhoveredHandler();
};