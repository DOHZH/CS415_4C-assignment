// Copyright Epic Games, Inc. All Rights Reserved.

#include "ACTGameMode.h"
#include "ACTCharacter.h"
#include "UObject/ConstructorHelpers.h"

AACTGameMode::AACTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
