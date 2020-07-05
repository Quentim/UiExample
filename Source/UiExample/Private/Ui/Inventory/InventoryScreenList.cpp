 #include "Ui/Inventory/InventoryScreenList.h"
#include "Components/WrapBox.h"
#include "Ui/Inventory/InventoryScreenItem.h"

 void UInventoryScreenList::SetItems(TArray<FInventoryItemData> InInventoryItems)
 {
	 InventoryItems = InInventoryItems;
	 RefreshList();
 }

 void UInventoryScreenList::SelectItem(const UInventoryScreenItem* InItem)
 {
	 SelectedListItem = InItem;
 	
	 for (auto* Item : ListItems)
	 {
		 Item->SetIsSelected(Item == InItem);
	 }
 }

 void UInventoryScreenList::SelectItemById(int32 Id)
 {
	 SelectedListItem = nullptr;
 	
	 for (auto* Item : ListItems)
	 {
		 if(Item->GetSetInventoryItemData().Id == Id)
		 {
			 SelectedListItem = Item;
			 Item->SetIsSelected(true);
		 }

		 Item->SetIsSelected(false);
	 }
 }
 
 int32 UInventoryScreenList::GetSelectedItemId() const
 {
 	if(!IsValid(SelectedListItem))
 	{
		return -1;
 	}
 	
	 return SelectedListItem->GetSetInventoryItemData().Id;
 }

 bool UInventoryScreenList::IsItemSelected() const
 {
	 return IsValid(SelectedListItem);
 }

 void UInventoryScreenList::RefreshList()
 {
	 ListItems.Empty();
 	
	 if(!IsValid(ListItemClass) || !IsValid(ItemsBox))
	 {
		 return;
	 } 	
 	
	 for (auto Item : InventoryItems)
	 {
		 UInventoryScreenItem* NewItem = Cast<UInventoryScreenItem>(CreateWidgetInstance(*this, ListItemClass, FName()));			

	 	if(!IsValid(NewItem))
	 	{
	 		continue;
	 	}

		NewItem->OnClicked.AddLambda([=](UInventoryScreenItem* InventoryItem) {SelectItem(InventoryItem); });		 	 	
		NewItem->SetInventoryItemData(Item);
		ListItems.Add(NewItem);
		auto* NewItemSlot = ItemsBox->AddChildToWrapBox(NewItem);
		SetItemStyle(NewItemSlot);	 	
	 }
 }
