// /***********************************************************************************
// *  File:             Kds_CoreCharacter.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "AlsCharacter.h"

#include "Kds_CoreCharacter.generated.h"

class UKds_AnimOverlaySettings;

/**
 *Core character class for the KdsCharacter module.
 * This class extends the AAlsCharacter class and includes additional functionality
 * for handling animation overlay settings and overlay mode changes.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API AKds_CoreCharacter : public AAlsCharacter
{
	GENERATED_BODY()

public:
	/**
	 * Default constructor.
	 */
	AKds_CoreCharacter();

protected:
	/**
	 * Called when the game starts or when spawned.
	 */
	virtual void BeginPlay() override;

	/**
	 * Called when the overlay mode is changed.
	 * @param PreviousOverlayMode - The previous overlay mode.
	 * @param NewOverlayMode - The new overlay mode.
	 */
	virtual void OnOverlayModeChanged_Implementation(const FGameplayTag& PreviousOverlayMode,
	                                                 const FGameplayTag& NewOverlayMode) override;


public:
	/**
	 * This is a test function for the documentation.
	 * @param NewOverlayMode - The new overlay mode.
	 * @return UObject& The object reference.
	 */
	UObject& TestFunctionDocs(const FGameplayTag& NewOverlayMode);

	/**
	 * Sets the overlay mode for the character.
	 * @param NewOverlayMode - The new overlay mode.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Animations")
	void SetOverlayModeTestDocs(const FGameplayTag& NewOverlayMode);

	/**
	 * This is a test function for the documentation.
	 *  returns a bool value. But it does not do anything, and is only used for testing.
	 *  is a blueprint callable function.
	 * @param OverlayModeTestParam - The overlay mode to check.
	 * @return True if the overlay mode is active, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "Kds|Character|Animations")
	bool IsOverlayModeActiveTestDocs(const FGameplayTag& OverlayModeTestParam) const;
	
protected:
	/** The animation overlay settings for the character. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings|Animations")
	TObjectPtr<UKds_AnimOverlaySettings> AnimOverlaySettings;
};
