 #include "Ui/Inventory/InventoryScreenList.h"
#include "Components/WrapBox.h"
#include "Ui/Inventory/InventoryScreenItem.h"

 void UInventoryScreenList::SetItems(TArray<FInventoryItemData> InInventoryItems)
 {
	 InventoryItems = InInventoryItems;
	 RefreshList();
 }

 void UInventoryScreenList::SelectItem(UInventoryScreenItem* InItem)
 {
	 SelectedListItem = InItem;
 	
	 for (auto* Item : ListItems)
	 {
		 Item->SetIsSelected(Item == InItem);
	 }
 }

 void UInventoryScreenList::SelectItemByData(FInventoryItemData Data)
 {
	 SelectedListItem = nullptr;
 	
	 for (auto* Item : ListItems)
	 {
		 if(Item->GetSetInventoryItem() == Data)
		 {
			 SelectedListItem = Item;
			 Item->SetIsSelected(true);
		 }

		 Item->SetIsSelected(false);
	 }
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

		NewItem->OnClciked.AddLambda([=](UInventoryScreenItem* InventoryItem) {SelectItem(InventoryItem); });		 	 	
		NewItem->SetInventoryItem(Item);
		ListItems.Add(NewItem);
		auto* NewItemSlot = ItemsBox->AddChildToWrapBox(NewItem);
		SetItemStyle(NewItemSlot);	 	
	 }
 }
