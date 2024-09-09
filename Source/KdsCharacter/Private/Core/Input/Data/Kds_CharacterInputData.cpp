#include "Core/Input/Data/Kds_CharacterInputData.h"

#include "KdsEnsureMacros.h"

void UKds_CharacterInputData::Validate() const
{
	KDS_ENSURE(InputMappingContext);
	KDS_ENSURE(LookMouseAction);
	KDS_ENSURE(LookAction);
	KDS_ENSURE(MoveAction);
	KDS_ENSURE(SprintAction);
	KDS_ENSURE(WalkAction);
	KDS_ENSURE(CrouchAction);
	KDS_ENSURE(JumpAction);
	KDS_ENSURE(AimAction);
	
	if(bEnableDebug)
	{
		KDS_ENSURE(SwitchViewModeAction);
	}
}

bool UKds_CharacterInputData::DebugEnabled() const
{
	return bEnableDebug;
}
