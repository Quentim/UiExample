 #include "Ui/Inventory/InventoryScreenItem.h"
#include "Components/Button.h"

 void UInventoryScreenItem::NativeConstruct()
 {
	 MainButton->OnClicked.AddUniqueDynamic(this, &UInventoryScreenItem::OnClickedHandler);
	 MainButton->OnHovered.AddUniqueDynamic(this, &UInventoryScreenItem::OnHoveredHandler);
	 MainButton->OnUnhovered.AddUniqueDynamic(this, &UInventoryScreenItem::OnUnhoveredHandler);
 	
	 Super::NativeConstruct();
 }

void UInventoryScreenItem::SetInventoryItem(FInventoryItemData InData)
{
	Data = InData;
	ResetWidget();
}

 FInventoryItemData UInventoryScreenItem::GetSetInventoryItem() const
 {
	 return Data;
 }

 void UInventoryScreenItem::SetIsSelected(bool InIsSelected)
 {
	 bIsSelected = InIsSelected;

 	if(bIsSelected)
 	{
		SetSelectedStyle();
		return;
 	}

 	if(IsHovered())
 	{
		SetHoveredStyle();
		return;
 	}

	SetRegularStyle(); 	
 }

 void UInventoryScreenItem::OnClickedHandler()
{
	OnClciked.Broadcast(this);
}

 void UInventoryScreenItem::OnHoveredHandler()
 {
 	if(bIsSelected)
 	{
		SetSelectedStyle();
		return;
 	}

	SetHoveredStyle(); 	
 }

 void UInventoryScreenItem::OnUnhoveredHandler()
 {
	 if (bIsSelected)
	 {
		 SetSelectedStyle();
		 return;
	 }

	 SetHoveredStyle();
 } 