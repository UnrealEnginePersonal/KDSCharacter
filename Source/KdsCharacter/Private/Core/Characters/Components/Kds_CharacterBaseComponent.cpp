// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Characters/Components/Kds_CharacterBaseComponent.h"

#include "Core/Characters/Kds_CoreCharacter.h"

UKds_CharacterBaseComponent::UKds_CharacterBaseComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UKds_CharacterBaseComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UKds_CharacterBaseComponent::GetCharacterOwner(class AKds_CoreCharacter*& OutCharacterOwner) const
{
	OutCharacterOwner = Cast<AKds_CoreCharacter>(GetOwner());	
}
