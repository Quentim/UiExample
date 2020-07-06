 #include "Ui/Inventory/InventoryScreenList.h"
#include "Components/WrapBox.h"
#include "Ui/Inventory/InventoryScreenItem.h"

 void UInventoryScreenList::SetItems(TArray<FInventoryItemData> InInventoryItems)
 {
	 InventoryItems = InInventoryItems;
	 RefreshList();
 }

 void UInventoryScreenList::SelectItem(FInventoryItemData Data)
 {
	 SeletedItemData = Data;
 	
	 for (auto* Item : ListItems)
	 {
		 Item->SetIsSelected(Item->GetSetInventoryItemData() == Data);
	 }
 } 
 
 FInventoryItemData UInventoryScreenList::GetSelectedData() const
 { 	
	return SeletedItemData;
 }

 bool UInventoryScreenList::IsItemSelected() const
 {
	 return SeletedItemData.Id > 0;
 }

 void UInventoryScreenList::RefreshList()
 {
	 ListItems.Empty();
 	
	 if (!IsValid(ItemsBox))
	 {
		 return;
	 }

	 ItemsBox->ClearChildren();	
 	
	 if(!IsValid(ListItemClass))
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

		NewItem->OnClicked.AddLambda([=](FInventoryItemData Data) {SelectItem(Data); OnItemSelected.Broadcast(Data); });
		NewItem->SetInventoryItemData(Item);
		ListItems.Add(NewItem);
		auto* NewItemSlot = ItemsBox->AddChildToWrapBox(NewItem);
		SetItemStyle(NewItemSlot);	 	
	 }
 }
