#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Game/InventoryItemData.h"
#include "InventoryItemDetails.generated.h"

UCLASS()
class UIEXAMPLE_API UInventoryItemDetails : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetInventoryItemData(FInventoryItemData InData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Show();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Hide();

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetWidget();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FInventoryItemData Data;
	
};
