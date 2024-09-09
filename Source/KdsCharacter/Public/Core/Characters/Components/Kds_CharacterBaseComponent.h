// /***********************************************************************************
// *  File:             Kds_CharacterBaseComponent.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024  Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kds_CharacterBaseComponent.generated.h"

/**
 * @brief Base component class for the KdsCharacter module.
 * This class extends the UActorComponent class and includes additional functionality
 * for handling character-specific behavior.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_CharacterBaseComponent : public UActorComponent
{
	GENERATED_BODY()

	UKds_CharacterBaseComponent();

protected:
	/**
	 * @brief The native begin play event for the character base component.
	 */
	virtual void BeginPlay() override;

public:
	/**
	 * @brief Get the character owner of the component.
	 * @param OutCharacterOwner The character owner of the component.
	 * @see AKds_CoreCharacter
	 * This function retrieves the kds character that owns this component.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Components")
	virtual void GetCharacterOwner(class AKds_CoreCharacter*& OutCharacterOwner) const;
};
