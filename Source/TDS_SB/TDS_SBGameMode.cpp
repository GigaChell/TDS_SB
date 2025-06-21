// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDS_SBGameMode.h"
#include "TDS_SBPlayerController.h"
#include "TDS_SBCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDS_SBGameMode::ATDS_SBGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDS_SBPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/Character/BP_TopDownCharacter"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
} 