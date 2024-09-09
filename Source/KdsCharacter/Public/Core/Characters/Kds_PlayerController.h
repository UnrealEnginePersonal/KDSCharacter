// /***********************************************************************************
// *  File:             Kds_PlayerController.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024  Kasper de Bruin
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "AlsPlayerController.h"
#include "Kds_PlayerController.generated.h"

/**
 * @brief The base player controller class for the KDS project.
 */
UCLASS(Blueprintable, BlueprintType)
class KDSCHARACTER_API AKds_PlayerController : public AAlsPlayerController
{
	GENERATED_BODY()

public:
	/**
	 * @brief The default constructor for the player controller.
	 */
	AKds_PlayerController();
};
