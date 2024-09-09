// /***********************************************************************************
// *  File:             CharacterMantleSettings.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterMantleSettings.generated.h"

/**
 * @brief The settings for mantling
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UCharacterMantleSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	/**
	 * @brief Remove the held object from the hand, when the character mantles.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	bool bRemoveHeldObjectOnMantle = true;

private:
};
