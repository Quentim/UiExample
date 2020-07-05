#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Ui/SortingMethod.h"
#include "InventoryScreenSortingPanel.generated.h"


UCLASS()
class UIEXAMPLE_API UInventoryScreenSortingPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	
	ESortingMethod GetSortingMethod();;
};
