// /***********************************************************************************
// *  File:             Kds_LinkedAnimInstanceSettings.h
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
#include "Kds_LinkedAnimInstanceSettings.generated.h"

/**
 * @brief Linked animation instance settings class for the KdsCharacter module.
 * This class extends the UDataAsset class and includes properties for managing
 * settings related to linked animation instances.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_LinkedAnimInstanceSettings : public UDataAsset
{
	GENERATED_BODY()

protected:
	/**
	 * @brief Enable impulse animations. If enabled, the linked animation instance will play impulse animations on sprint.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Kds|Character|Settings")
	bool bPlayImpulseAnimations = false;
};
