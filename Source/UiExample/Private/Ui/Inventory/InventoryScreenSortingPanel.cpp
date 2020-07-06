#include "Ui/Inventory/InventoryScreenSortingPanel.h"
#include "Components/WrapBox.h"

void UInventoryScreenSortingPanel::SetSortingMethods(TArray<ESortingMethod> InMethods)
{
	SortingMethods = InMethods;
	RefreshList();
} 

ESortingMethod UInventoryScreenSortingPanel::GetSelectedSortingMethod()
{
	return SelectedSortingMethod;
}

void UInventoryScreenSortingPanel::SelectSortingMethods(ESortingMethod InMethod)
{
	SelectedSortingMethod = InMethod;

	for (auto* Button : Buttons)
	{
		Button->SetIsSelected(Button->GetSortingMethod() == InMethod);
	}
}

void UInventoryScreenSortingPanel::RefreshList()
{
	Buttons.Empty();
	
	if(!IsValid(ButtonsBox))
	{
		return;
	}

	ButtonsBox->ClearChildren();

	if (!IsValid(SortingButtonClass) || !IsValid(ButtonsBox))
	{
		return;
	}

	for (auto Method : SortingMethods)
	{
		UInventoryScreenSortingButton* NewButton = Cast<UInventoryScreenSortingButton>(CreateWidgetInstance(*this, SortingButtonClass, FName()));

		if (!IsValid(NewButton))
		{
			continue;
		}

		NewButton->OnClicked.AddLambda([this](ESortingMethod InMethod)
		{
			SelectSortingMethods(InMethod);
			OnMethodSelected.Broadcast(InMethod);
		});
		NewButton->SetSortingMethod(Method);
		Buttons.Add(NewButton);
		ButtonsBox->AddChild(NewButton);
	}	
}