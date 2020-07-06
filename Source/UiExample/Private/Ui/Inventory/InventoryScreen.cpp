#include "Ui/Inventory/InventoryScreen.h"


#include "UI/Inventory/InventoryItemDetails.h"
#include "Ui/Inventory/InventoryScreenList.h"
#include "Ui/Inventory/InventoryScreenModel.h"
#include "Ui/Inventory/InventoryScreenSortingPanel.h"

void UInventoryScreen::NativeConstruct()
{
	if(!IsValid(InventoryList) || !IsValid(Details) || !IsValid(SortingPanel))
	{
		return;
	}
	
	SortingPanel->SetSortingMethods({ESortingMethod::ByRarity, ESortingMethod::ByValue, ESortingMethod::ByName});
	SortingPanel->SelectSortingMethods(DefaultSortingMethod);
	SortingPanel->OnMethodSelected.AddLambda([this](ESortingMethod Method) { ResetList(); });

	Details->Hide();

	InventoryList->OnItemSelected.AddLambda([this](FInventoryItemData Data)
	{
		Details->SetInventoryItemData(Data);
		Details->Show();
	});
} 

void UInventoryScreen::InitWithModel(UInventoryScreenModel* InModel)
{
	if(!IsValid(InModel))
	{
		return;
	}
	
	Model = InModel;
	Model->OnInventoryItemsChanged.AddLambda([this]() {ResetList();});
}

void UInventoryScreen::ResetList()
{ 
	if(!IsValid(Model) || !IsValid(InventoryList) || !IsValid(Details))
	{
		return;
	}

	Details->Hide();
	
	auto CurrentSelectedData = InventoryList->GetSelectedData();

	auto NewInventoryItems(Model->GetInventoryItems());
	SortInventoryItems(NewInventoryItems);	
	InventoryList->SetItems(NewInventoryItems);

	if (CurrentSelectedData.Id < 0)
	{
		return;		 
	}
	
	InventoryList->SelectItem(CurrentSelectedData);
	Details->Show();
}

void UInventoryScreen::SortInventoryItems(TArray<FInventoryItemData>& InventoryItems)
{
	if(!IsValid(SortingPanel))
	{
		return;
	}
	
	switch (SortingPanel->GetSelectedSortingMethod())
	{
		case ESortingMethod::ByName:
		InventoryItems.Sort([](FInventoryItemData A, FInventoryItemData B) {return A.Name.ToString() <= B.Name.ToString(); });
		break;

		case ESortingMethod::ByRarity:
		InventoryItems.Sort([](FInventoryItemData A, FInventoryItemData B) {return int(A.Rarity) >= int(B.Rarity); });
		break;

		case ESortingMethod::ByValue:
		InventoryItems.Sort([](FInventoryItemData A, FInventoryItemData B) {return A.Value >= B.Value; });
		break;

		default:
		break;
	}	
}
