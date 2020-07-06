#include "UI/Inventory/InventoryItemDetails.h"

void UInventoryItemDetails::SetInventoryItemData(FInventoryItemData InData)
{
	Data = InData;
	ResetWidget();
}
