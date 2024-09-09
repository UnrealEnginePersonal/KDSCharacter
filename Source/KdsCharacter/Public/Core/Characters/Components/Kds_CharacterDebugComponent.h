// /***********************************************************************************
// *  File:             Kds_CharacterDebugComponent.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kds_CharacterDebugComponent.generated.h"

/**
 * @brief Debug component class for the KdsCharacter module.
 * This class extends the UActorComponent class and includes additional functionality
 * for handling character-specific debug behavior.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_CharacterDebugComponent : public UActorComponent
{
	GENERATED_BODY()

	/**
	 * @brief The default constructor for the character debug component.
	 * Sets default values for this component's properties.
	 */
	UKds_CharacterDebugComponent();

protected:
	/**
	 * @brief The native begin play event for the character debug component.
	 * This function is called when the game starts or when the component is spawned.
	 */
	virtual void BeginPlay() override;
};
