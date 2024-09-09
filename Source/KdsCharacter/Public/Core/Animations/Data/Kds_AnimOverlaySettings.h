// /***********************************************************************************
// *  File:             Kds_AnimOverlaySettings.h
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
#include "GameplayTags.h"

#include "Kds_AnimOverlaySettings.generated.h"

class UKds_LinkedAnimInstance;

/**
 * @brief Animation overlay settings class for the KdsCharacter module.
 * This class extends the UDataAsset class and includes properties for managing
 * animation overlays based on gameplay tags.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_AnimOverlaySettings : public UDataAsset
{
	GENERATED_BODY()

public:
	/**
	 * @brief The default fallback overlay animation instance.
	 * this is used when the character wants to switch overlays, but there is nog overlay found coresponding to the
	 * gameplay tag.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|AnimOverlay")
	TSubclassOf<UKds_LinkedAnimInstance> DefaultAnimOverlay;

	/**
	 * @brief The map of gameplay tags to overlay animation instances.
	 * This is used to determine which overlay to use based on the current overlay mode.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|AnimOverlay")
	TMap<FGameplayTag, TSubclassOf<UKds_LinkedAnimInstance>> AnimOverlayMap;
};
