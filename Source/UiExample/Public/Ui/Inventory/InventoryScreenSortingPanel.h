#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryScreenSortingButton.h"
#include "Ui/SortingMethod.h"
#include "InventoryScreenSortingPanel.generated.h"

class UButton;
class UWrapBox;

UCLASS()
class UIEXAMPLE_API UInventoryScreenSortingPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void SetSortingMethods(TArray<ESortingMethod> InMethods);	
	UFUNCTION(BlueprintPure)
	ESortingMethod GetSelectedSortingMethod();

	UFUNCTION(BlueprintCallable)
	void SelectSortingMethods(ESortingMethod InMethod); 

	FSortingMethodButtonDelegate OnMethodSelected;

protected:

	UFUNCTION(BlueprintCallable)
	void RefreshList();

	UPROPERTY()
	TArray<UInventoryScreenSortingButton*> Buttons;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<ESortingMethod> SortingMethods;

	UPROPERTY(BlueprintReadOnly)
	ESortingMethod SelectedSortingMethod;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<UInventoryScreenSortingButton> SortingButtonClass;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UWrapBox* ButtonsBox = nullptr;
	
};
