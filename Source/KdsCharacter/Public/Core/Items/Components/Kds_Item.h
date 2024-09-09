// /***********************************************************************************
// *  File:             Kds_Item.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024  Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"

#include "Kds_Item.generated.h"

class AKds_PlayableCharacter;

/// The item class for the KDS project.
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_Item : public UActorComponent
{
	GENERATED_BODY()

public:	
	UKds_Item();

public:
	/// This event needs to be called when the item is equipped by the character.
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Items")
	virtual void OnEquipped(
		/// The character that the item is being equipped to.
		class AKds_PlayableCharacter* Character);

	/// This event needs to be called when the item is unequipped by the character.
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Items")
	virtual void OnUnequipped(
		/// The character that the item is being unequipped from.
		class AKds_PlayableCharacter* Character);

	/**
	 * @brief Called when the item is used by the character.
	 * @param Character The character that is using the item.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Items")
	virtual void OnUsed(class AKds_PlayableCharacter* Character);

	/**
	 * @brief Called when the item is dropped by the character.
	 * @param Character The character that is dropping the item.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Items")
	virtual void OnDropped(class AKds_PlayableCharacter* Character);

	/**
	 * @brief Called when the item is picked up by the character.
	 * @param Character The character that is picking up the item.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Items")
	virtual void OnPickedUp(class AKds_PlayableCharacter* Character);

	/**
	 * @brief Called when the item is destroyed.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Items")
	virtual void OnDestroyed();
};
