// /***********************************************************************************
// *  File:             KdsCharacterModule.h
// *  Project:          Kds_CharacterModule
// *  Author(s):        Kasper de Bruin
// *  Created:          03-09-2024
// *
// *  Copyright (c) 2024 Kasper de Bruin 
// *  All rights reserved.
// **/

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * @brief The module interface for the KdsCharacter module.
 */
class FKdsCharacterModule : public IModuleInterface
{
public:
	/**
	 * @brief Startup the module implementation.
	 */
	virtual void StartupModule() override;

	/**
	 * @brief Shutdown the module implementation.
	 */
	virtual void ShutdownModule() override;
};
