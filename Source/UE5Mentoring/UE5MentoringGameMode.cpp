// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5MentoringGameMode.h"
#include "UE5MentoringCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5MentoringGameMode::AUE5MentoringGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
