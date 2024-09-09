// /***********************************************************************************
// *  File:             Kds_CharacterInputData.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "Kds_CharacterInputData.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * @brief The input data asset for the KdsCharacter module.
 * This class holds all the input actions and settings for the KdsCharacter.
 * It includes various input actions such as movement, looking around, sprinting, 
 * walking, crouching, jumping, aiming, and switching view modes. It also includes 
 * settings for mouse sensitivity and look rates.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API UKds_CharacterInputData : public UDataAsset
{
	GENERATED_BODY()

public:
	/**
	 * @brief Get debug enabled 
	 * @return if debugging is enabled
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Input")
	bool DebugEnabled() const;

public:
	/**
	 * @brief Validates the input actions assets. This should be called from the character BeginPlay().
	 */
	void Validate() const;

public:
	/**
	 * @brief The input mapping context for the character.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputMappingContext> InputMappingContext;

	/**
	 * @brief The input action for looking around with the mouse.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> LookMouseAction;

	/**
	 * @brief The input action for looking around.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> LookAction;

	/**
	 * @brief The input action for moving.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> MoveAction;

	/**
	 * @brief The input action for sprinting.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> SprintAction;

	/**
	 * @brief The input action for walking.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> WalkAction;

	/**
	 * @brief The input action for crouching.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> CrouchAction;

	/**
	 * @brief The input action for jumping.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> JumpAction;

	/**
	 * @brief The input action for aiming.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings", Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> AimAction;

	/**
	 * @brief The sensitivity for looking up with the mouse.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kds|Character|Settings",
		Meta = (ClampMin = "0", ForceUnits = "x"))
	float LookUpMouseSensitivity = 1.0f;

	/**
	 * @brief The sensitivity for looking right with the mouse.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kds|Character|Settings",
		Meta = (ClampMin = "0", ForceUnits = "x"))
	float LookRightMouseSensitivity = 1.0f;

	/**
	 * @brief The rate for looking up.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kds|Character|Settings",
		Meta = (ClampMin = "0", ForceUnits = "deg/s"))
	float LookUpRate = 90.0f;

	/**
	 * @brief The rate for looking right.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kds|Character|Settings",
		Meta = (ClampMin = "0", ForceUnits = "deg/s"))
	float LookRightRate = 240.0f;

	/**
	 * @brief If true, enables debug mode.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Debug|Settings",
		Meta = (DisplayThumbnail = false))
	bool bEnableDebug = true;

	/**
	 * @brief The input action for switching view modes.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Debug|Settings",
		Meta = (DisplayThumbnail = false))
	TObjectPtr<UInputAction> SwitchViewModeAction;
};
