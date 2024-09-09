// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Characters/Kds_PlayableCharacter.h"


#include "AlsCameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "KdsEnsureMacros.h"

#include "Core/Input/Data/Kds_CharacterInputData.h"

#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "Utility/AlsVector.h"

// Sets default values
AKds_PlayableCharacter::AKds_PlayableCharacter()
{
	Camera = CreateDefaultSubobject<UAlsCameraComponent>(FName{TEXTVIEW("Camera")});
	Camera->SetupAttachment(GetMesh());
	Camera->SetRelativeRotation_Direct({0.0f, 90.0f, 0.0f});

	
	
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AKds_PlayableCharacter::NotifyControllerChanged()
{
	const auto* PreviousPlayer{Cast<APlayerController>(PreviousController)};
	if (IsValid(PreviousPlayer))
	{
		auto* InputSubsystem{ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PreviousPlayer->GetLocalPlayer())};
		if (IsValid(InputSubsystem))
		{
			InputSubsystem->RemoveMappingContext(InputData->InputMappingContext);
		}
	}

	auto* NewPlayer{Cast<APlayerController>(GetController())};
	if (IsValid(NewPlayer))
	{
		NewPlayer->InputYawScale_DEPRECATED = 1.0f;
		NewPlayer->InputPitchScale_DEPRECATED = 1.0f;
		NewPlayer->InputRollScale_DEPRECATED = 1.0f;

		auto* InputSubsystem{ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(NewPlayer->GetLocalPlayer())};
		if (IsValid(InputSubsystem))
		{
			FModifyContextOptions Options;
			Options.bNotifyUserSettings = true;

			InputSubsystem->AddMappingContext(InputData->InputMappingContext, 0, Options);
		}
	}

	Super::NotifyControllerChanged();
}

/************************************************************
 * Input
 ************************************************************/	
void AKds_PlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto* EnhancedInput{Cast<UEnhancedInputComponent>(PlayerInputComponent)};
	if(EnhancedInput)
	{
		EnhancedInput->BindAction(InputData->LookMouseAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnLookMouse);
		EnhancedInput->BindAction(InputData->LookMouseAction, ETriggerEvent::Canceled, this, &ThisClass::Input_OnLookMouse);

		EnhancedInput->BindAction(InputData->LookAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnLook);
		EnhancedInput->BindAction(InputData->LookAction, ETriggerEvent::Canceled, this, &ThisClass::Input_OnLook);

		EnhancedInput->BindAction(InputData->MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnMove);
		EnhancedInput->BindAction(InputData->MoveAction, ETriggerEvent::Canceled, this, &ThisClass::Input_OnMove);

		EnhancedInput->BindAction(InputData->SprintAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnSprint);
		EnhancedInput->BindAction(InputData->SprintAction, ETriggerEvent::Canceled, this, &ThisClass::Input_OnSprint);
		
		EnhancedInput->BindAction(InputData->WalkAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnWalk);

		EnhancedInput->BindAction(InputData->CrouchAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnCrouch);

		EnhancedInput->BindAction(InputData->JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnJump);
		EnhancedInput->BindAction(InputData->JumpAction, ETriggerEvent::Canceled, this, &ThisClass::Input_OnJump);
		
		EnhancedInput->BindAction(InputData->AimAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnAim);
		EnhancedInput->BindAction(InputData->AimAction, ETriggerEvent::Canceled, this, &ThisClass::Input_OnAim);

		if(InputData->DebugEnabled())
		{
			EnhancedInput->BindAction(InputData->SwitchViewModeAction, ETriggerEvent::Triggered, this, &ThisClass::Input_OnViewMode);
		}
	}else
	{
		
	}
}

void AKds_PlayableCharacter::CalcCamera(float DeltaTime, FMinimalViewInfo& ViewInfo)
{
	if (Camera->IsActive())
	{
		Camera->GetViewInfo(ViewInfo);
		return;
	}

	Super::CalcCamera(DeltaTime, ViewInfo);
}

void AKds_PlayableCharacter::Input_OnLookMouse(const FInputActionValue& ActionValue)
{	
	const FVector2f Value{ActionValue.Get<FVector2D>()};

	AddControllerPitchInput(Value.Y * InputData->LookUpMouseSensitivity);
	AddControllerYawInput(Value.X * InputData->LookRightMouseSensitivity);
}

void AKds_PlayableCharacter::Input_OnLook(const FInputActionValue& ActionValue)
{
	
	const FVector2f Value{ActionValue.Get<FVector2D>()};

	AddControllerPitchInput(Value.Y * InputData->LookUpRate);
	AddControllerYawInput(Value.X * InputData->LookRightRate);
}

void AKds_PlayableCharacter::Input_OnMove(const FInputActionValue& ActionValue)
{
	const auto Value{UAlsVector::ClampMagnitude012D(ActionValue.Get<FVector2D>())};

	const auto ForwardDirection{UAlsVector::AngleToDirectionXY(UE_REAL_TO_FLOAT(GetViewState().Rotation.Yaw))};
	const auto RightDirection{UAlsVector::PerpendicularCounterClockwiseXY(ForwardDirection)};

	AddMovementInput(ForwardDirection * Value.Y + RightDirection * Value.X);
}

void AKds_PlayableCharacter::Input_OnSprint(const FInputActionValue& ActionValue)
{
	SetDesiredGait(ActionValue.Get<bool>() ? AlsGaitTags::Sprinting : AlsGaitTags::Running);
}

void AKds_PlayableCharacter::Input_OnWalk()
{
	if (GetDesiredGait() == AlsGaitTags::Walking)
	{
		SetDesiredGait(AlsGaitTags::Running);
	}
	else if (GetDesiredGait() == AlsGaitTags::Running)
	{
		SetDesiredGait(AlsGaitTags::Walking);
	}
}

void AKds_PlayableCharacter::Input_OnCrouch()
{
	if (GetDesiredStance() == AlsStanceTags::Standing)
	{
		SetDesiredStance(AlsStanceTags::Crouching);
	}
	else if (GetDesiredStance() == AlsStanceTags::Crouching)
	{
		SetDesiredStance(AlsStanceTags::Standing);
	}
}

void AKds_PlayableCharacter::Input_OnJump(const FInputActionValue& ActionValue)
{
	if (ActionValue.Get<bool>())
	{
		if (StopRagdolling())
		{
			return;
		}

		if (StartMantlingGrounded())
		{
			return;
		}

		if (GetStance() == AlsStanceTags::Crouching)
		{
			SetDesiredStance(AlsStanceTags::Standing);
			return;
		}

		Jump();
	}
	else
	{
		StopJumping();
	}
}

void AKds_PlayableCharacter::Input_OnAim(const FInputActionValue& ActionValue)
{
	SetDesiredAiming(ActionValue.Get<bool>());
}

void AKds_PlayableCharacter::Input_OnViewMode()
{
	SetViewMode(GetViewMode() == AlsViewModeTags::ThirdPerson ? AlsViewModeTags::FirstPerson : AlsViewModeTags::ThirdPerson);
}


