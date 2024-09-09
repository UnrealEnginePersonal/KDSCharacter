// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Characters/Kds_CoreCharacter.h"
#include "Core/Animations/Data/Kds_AnimOverlaySettings.h"

#include "KdsEnsureMacros.h"
#include "Core/Animations/Kds_LinkedAnimInstance.h"

// Sets default values
AKds_CoreCharacter::AKds_CoreCharacter()
{
	
}

void AKds_CoreCharacter::BeginPlay()
{
	//Validation
	KDS_ENSURE(IsValid(AnimOverlaySettings));
	
	Super::BeginPlay();
}

#include "Kds_Log.h"
void AKds_CoreCharacter::OnOverlayModeChanged_Implementation(const FGameplayTag& PreviousOverlayMode,
															 const FGameplayTag& NewOverlayMode)
{
	auto* CharMesh = this->GetMesh();
	KDS_ENSURE(IsValid(CharMesh));

	// find the animation layer in the map to use
	if (const TSubclassOf<UKds_LinkedAnimInstance>* CurrentAnimOverlay =
			AnimOverlaySettings->AnimOverlayMap.Find(NewOverlayMode))
	{
		CharMesh->LinkAnimClassLayers(*CurrentAnimOverlay);
	}
	else
	{
		// if the animation layer is not found, use the default animation layer
		CharMesh->LinkAnimClassLayers(AnimOverlaySettings->DefaultAnimOverlay);
	}
}
UObject& AKds_CoreCharacter::TestFunctionDocs(const FGameplayTag& NewOverlayMode)
{
	return *this;
}

void AKds_CoreCharacter::SetOverlayModeTestDocs(const FGameplayTag& NewOverlayMode)
{
	// Validation
	KDS_ENSURE(IsValid(AnimOverlaySettings));

	UE_LOG(LogTemp, Warning, TEXT("SetOverlayMode: %s from %s. this is only for testing documentations"),
		   *NewOverlayMode.ToString(), *GetName());
}
bool AKds_CoreCharacter::IsOverlayModeActiveTestDocs(const FGameplayTag& OverlayModeTestParam) const
{
	return false;
}
