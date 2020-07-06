#include "Ui/Inventory/InventoryScreenSortingButton.h"

#include "Components/Button.h"

void UInventoryScreenSortingButton::NativeConstruct()
{
	MainButton->OnClicked.AddUniqueDynamic(this, &UInventoryScreenSortingButton::OnClickedHandler);
}

void UInventoryScreenSortingButton::SetSortingMethod(ESortingMethod InMethod)
{
	SortingMethod = InMethod;
	ResetWidget();
}

ESortingMethod UInventoryScreenSortingButton::GetSortingMethod() const
{
	return SortingMethod;
}

void UInventoryScreenSortingButton::SetIsSelected(bool InIsSelected)
{
	if (InIsSelected)
	{
		SetSelectedStyle();
		return;
	}

	SetRegularStyle();
}

void UInventoryScreenSortingButton::OnClickedHandler()
{
	 OnClicked.Broadcast(SortingMethod);
}
