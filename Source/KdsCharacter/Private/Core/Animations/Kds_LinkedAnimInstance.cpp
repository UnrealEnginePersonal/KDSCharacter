// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animations/Kds_LinkedAnimInstance.h"

#include "KdsEnsureMacros.h"

#include "Core/Animations/Data/Kds_LinkedAnimInstanceSettings.h"

UKds_LinkedAnimInstance::UKds_LinkedAnimInstance()
{
	Settings = nullptr;
}

void UKds_LinkedAnimInstance::NativeBeginPlay()
{
	KDS_ENSURE(IsValid(Settings));

	Super::NativeBeginPlay();
}
void UKds_LinkedAnimInstance::OnOverlayModeChangedDocumentationTest(const FGameplayTag& PreviousOverlayMode,
																	const FGameplayTag& NewOverlayMode)
{
	// This is a test function for documentation generation.
    // It does not do anything, and is only used for testing.
    // It is not a blueprint callable function.
}
