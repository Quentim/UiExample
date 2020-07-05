#include "Ui/Inventory/InventoryScreen.h"

#include "Ui/Inventory/InventoryScreenList.h"
#include "Ui/Inventory/InventoryScreenModel.h"
#include "Ui/Inventory/InventoryScreenSortingPanel.h"

void UInventoryScreen::InitWithModel(UInventoryScreenModel* InModel)
{
	if(!IsValid(InModel))
	{
		return;
	}
	
	Model = InModel;
	Model->OnInventoryItemsChanged.AddLambda([this]() {ResetScreen();});	
}

void UInventoryScreen::ResetScreen()
{ 
	if(!IsValid(Model) || !IsValid(InventoryList))
	{
		return;
	}

	const int32 CurrentSelectedItemId = InventoryList->GetSelectedItemId();

	auto NewInventoryItems(Model->GetInventoryItems());
	SortInventoryItems(NewInventoryItems);	
	InventoryList->SetItems(NewInventoryItems);

	if (CurrentSelectedItemId > 0)
	{
		InventoryList->SelectItemById(CurrentSelectedItemId);
	}	
}

void UInventoryScreen::SortInventoryItems(TArray<FInventoryItemData>& InventoryItems)
{
	if(!IsValid(SortingPanel))
	{
		return;
	}
	
	switch (SortingPanel->GetSortingMethod())
	{
		case ESortingMethod::ByName:
		InventoryItems.Sort([](FInventoryItemData A, FInventoryItemData B) {return A.Name.ToString() <= B.Name.ToString(); });
		break;

		case ESortingMethod::ByRarity:
		InventoryItems.Sort([](FInventoryItemData A, FInventoryItemData B) {return int(A.Rarity) <= int(B.Rarity); });
		break;

		case ESortingMethod::ByValue:
		InventoryItems.Sort([](FInventoryItemData A, FInventoryItemData B) {return A.Value <= B.Value; });
		break;

		default:
		break;
	}	
}
