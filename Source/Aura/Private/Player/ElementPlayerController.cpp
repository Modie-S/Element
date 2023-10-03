// Copywright MaxiMod Games 2023



// This file's header
#include "Player/ElementPlayerController.h"

// Unreal Engine
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



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

void AElementPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent >( InputComponent );

	EnhancedInputComponent->BindAction( MoveAction, ETriggerEvent::Triggered, this, &AElementPlayerController::Move );
}

void AElementPlayerController::Move( const FInputActionValue& InputActionValue )
{
	const FVector2D InputAxisVector = InputActionValue.Get< FVector2D >();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation( 0.f, Rotation.Yaw, 0.f );

	const FVector ForwardDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::X );
	const FVector RightDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::Y );

	if ( APawn* ControlledPawn = GetPawn< APawn >() )
	{
		ControlledPawn->AddMovementInput( ForwardDirection, InputAxisVector.Y );
		ControlledPawn->AddMovementInput( RightDirection, InputAxisVector.X );
	}
}
