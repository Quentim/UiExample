#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Ui/SortingMethod.h"
#include "InventoryScreenSortingButton.generated.h"

class UButton;

DECLARE_MULTICAST_DELEGATE_OneParam(FSortingMethodButtonDelegate, ESortingMethod);
 
UCLASS()
class UIEXAMPLE_API UInventoryScreenSortingButton : public UUserWidget
{
	GENERATED_BODY()			

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetSortingMethod(ESortingMethod InMethod);
	UFUNCTION(BlueprintCallable)
	ESortingMethod GetSortingMethod() const;

	void SetIsSelected(bool InIsSelected); 

	FSortingMethodButtonDelegate OnClicked;

protected:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetWidget();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSelectedStyle();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetRegularStyle();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	ESortingMethod SortingMethod;

	UPROPERTY(BlueprintReadOnly, meta = (Bindwidget))
	UButton* MainButton = nullptr;	

private:

	UFUNCTION()
	void OnClickedHandler();
	
};