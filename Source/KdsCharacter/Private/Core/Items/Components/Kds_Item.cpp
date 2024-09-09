#include "Core/Items/Components/Kds_Item.h"


UKds_Item::UKds_Item()
{
	bCanEverAffectNavigation = false;
	PrimaryComponentTick.bCanEverTick = false;
}

void UKds_Item::OnEquipped(class AKds_PlayableCharacter* Character)
{
}

void UKds_Item::OnUnequipped(class AKds_PlayableCharacter* Character)
{
}

void UKds_Item::OnUsed(class AKds_PlayableCharacter* Character)
{
}

void UKds_Item::OnDropped(class AKds_PlayableCharacter* Character)
{
}

void UKds_Item::OnPickedUp(class AKds_PlayableCharacter* Character)
{
}

void UKds_Item::OnDestroyed()
{
}
