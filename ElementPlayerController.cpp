// Copywright MaxiMod Games 2023



// This file's header
#include "Player/ElementPlayerController.h"

// Unreal Engine
#include "EnhancedInputSubsystems.h"

AElementPlayerController::AElementPlayerController()
{
	bReplicates = true;
}

void AElementPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check( ElementContext );

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem >( GetLocalPlayer() );
	check( Subsystem );
	Subsystem->AddMappingContext( ElementContext, 0 );

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior( EMouseLockMode::DoNotLock );
	InputModeData.SetHideCursorDuringCapture( false );
	SetInputMode( InputModeData );
}
