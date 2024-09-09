// Copyright Epic Games, Inc. All Rights Reserved.

#include "KdsCharacterModule.h"
#include "Kds_Log.h"
#include "Core/Logging/KdsCharacterLog.h"

#define LOCTEXT_NAMESPACE "FKdsCharacterModule"


//* UNLOG( MySpecificCategory, Warning )( "Logging on a specific category" );
void FKdsCharacterModule::StartupModule()
{
	FUnlog::Log<FKdsCharacterModule>(TEXT("Starting up KdsCharacter module..."));
}

void FKdsCharacterModule::ShutdownModule()
{
	FUnlog::Log<FKdsCharacterModule>(TEXT("Shutting down KdsCharacter module..."));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FKdsCharacterModule, KdsCharacter)