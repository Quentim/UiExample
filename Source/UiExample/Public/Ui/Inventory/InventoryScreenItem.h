#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/InventoryItemData.h"
#include "InventoryScreenItem.generated.h"

class UButton;

UCLASS()
class UIEXAMPLE_API UInventoryScreenItem : public UUserWidget
{
	DECLARE_MULTICAST_DELEGATE_OneParam(FInventoryItemDataDelegate, FInventoryItemData);
		
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetInventoryItemData(FInventoryItemData InData);
	UFUNCTION(BlueprintPure)
	FInventoryItemData GetSetInventoryItemData() const;

	UFUNCTION(BlueprintCallable)
	void SetIsSelected(bool InIsSelected);
	
	FInventoryItemDataDelegate OnClicked;

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetWidget();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSelectedStyle();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetRegularStyle();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHoveredStyle();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FInventoryItemData Data;

	UPROPERTY(BlueprintReadOnly)
	bool bIsSelected;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UButton* MainButton = nullptr;

private:

	UFUNCTION()
	void OnClickedHandler();
	UFUNCTION()
	void OnHoveredHandler();
	UFUNCTION()
	void OnUnhoveredHandler();
};