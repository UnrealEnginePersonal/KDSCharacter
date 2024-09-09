// /***********************************************************************************
// *  File:             Kds_PlayableCharacter.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "Kds_CoreCharacter.h"
#include "Kds_PlayableCharacter.generated.h"

struct FInputActionValue;

class UKds_CharacterInputData;
class UAlsCameraComponent;
class UInputMappingContext;
class UInputAction;

/**
 * @brief Playable character class for the KdsCharacter module.
 * This class extends the AKds_CoreCharacter class and includes additional functionality
 * for handling the basic movement, this class also handles the input actions for the character and camera.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API AKds_PlayableCharacter : public AKds_CoreCharacter
{
	GENERATED_BODY()

public:
	/**
	 * @brief The default constructor for the playable character.
	 */
	AKds_PlayableCharacter();

protected:
	/**
	 * @brief The event that is called when the character is possessed/changed by a controller.
	 */
	virtual void NotifyControllerChanged() override;

#pragma region Camera

protected:
	/**
	 * @brief Calculates the camera for the character.
	 * @param DeltaTime The delta time
	 * @param ViewInfo The view info
	 */
	virtual void CalcCamera(float DeltaTime, FMinimalViewInfo& ViewInfo) override;

protected:
	/**
	 * @brief The camera component for the character.
	 */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Kds|Character|Camera")
	TObjectPtr<UAlsCameraComponent> Camera;

#pragma endregion

#pragma region Input

protected:
	/**
	 * @brief Sets up and binds the player input component for the character. 
	 * @param Input The Enhanced Input plugin input component.
	 */
	virtual void SetupPlayerInputComponent(UInputComponent* Input) override;

private:
	/**
	 * @brief Input action for looking with the mouse.	
	 * @param ActionValue The action value
	 */
	virtual void Input_OnLookMouse(const FInputActionValue& ActionValue);
	/**
	 * @brief Input action for looking around.
	 * @param ActionValue The action value
	 */
	virtual void Input_OnLook(const FInputActionValue& ActionValue);
	/**
	 * @brief Input action for moving.
	 * @param ActionValue The action value
	 */
	virtual void Input_OnMove(const FInputActionValue& ActionValue);
	/**
     * @brief Input action for sprinting.
     * @param ActionValue The action value
     */
	virtual void Input_OnSprint(const FInputActionValue& ActionValue);
	/**
	 * @brief Input action for walking.
	 */
	virtual void Input_OnWalk();
	/**
	 * @brief Input action for crouching.
	 */
	virtual void Input_OnCrouch();
	/**
     * @brief Input action for jumping.
     * @param ActionValue The action value
     */
	virtual void Input_OnJump(const FInputActionValue& ActionValue);
	/**
     * @brief Input action for aiming.
     * @param ActionValue The action value
     */
	virtual void Input_OnAim(const FInputActionValue& ActionValue);
	/**
     * @brief Input action for switching view modes.
     */
	virtual void Input_OnViewMode();

protected:
	/**
	 * @brief The input data for the character.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Kds|Character|Settings|Input")
	TObjectPtr<UKds_CharacterInputData> InputData;
#pragma endregion
};