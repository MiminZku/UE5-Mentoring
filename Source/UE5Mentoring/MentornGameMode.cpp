// Copyright Epic Games, Inc. All Rights Reserved.

#include "MentornGameMode.h"
#include "MentornCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMentornGameMode::AMentornGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
