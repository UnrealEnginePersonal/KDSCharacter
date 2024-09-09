// /***********************************************************************************
// *  File:             Kds_LinkedAnimInstance.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "AlsLinkedAnimationInstance.h"

#include "Kds_LinkedAnimInstance.generated.h"


struct FGameplayTag;
class UKds_LinkedAnimInstanceSettings;

/**
 * Linked animation instance class for the KdsCharacter module.
 * This class extends the UAlsLinkedAnimationInstance class and includes additional functionality
 * for handling settings related to linked animation instances.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_LinkedAnimInstance : public UAlsLinkedAnimationInstance
{
	GENERATED_BODY()

public:
	/**
	 * Default constructor.
	 */
	UKds_LinkedAnimInstance();

public:
	/**
	 * Called when begin play
	 */
	virtual void NativeBeginPlay() override;

	/**
	* Function called when the overlay mode has changed.
	* 
	* @param PreviousOverlayMode - The previous overlay mode.
	* @param NewOverlayMode - The new overlay mode.
	*/
	void OnOverlayModeChangedDocumentationTest(const FGameplayTag& PreviousOverlayMode, const FGameplayTag& NewOverlayMode);
	
public:
	/**
	 * The settings for the linked animation instance.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Kds|Character|Settings")
	TObjectPtr<UKds_LinkedAnimInstanceSettings> Settings;
};
