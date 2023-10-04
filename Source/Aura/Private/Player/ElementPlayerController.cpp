// Copywright MaxiMod Games 2023


// This file's header
#include "Player/ElementPlayerController.h"

// Unreal Engine
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AElementPlayerController::AElementPlayerController()
{
	bReplicates = true;
}

void AElementPlayerController::PlayerTick( float DeltaTime )
{
	Super::PlayerTick( DeltaTime );

	CursorTrace();
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

void AElementPlayerController::CursorTrace()
{
	FHitResult CursorTraceHit;
	GetHitResultUnderCursor( ECC_Visibility, false, CursorTraceHit );
	if ( !CursorTraceHit.bBlockingHit )
	{
		return;
	}

	LastActor = CurrentActor;
	CurrentActor = Cast< IEnemyInterface >( CursorTraceHit.GetActor() );

	// Line trace from cursor. Several scenarios for this:
	// A. LastActor is null, CurrentActor is null - do nothing
	// B. LastActor is null, CurrentActor is not null - highlight CurrentActor
	// C. LastActor is not null, CurrentActor is null - unhighlight LastActor
	// D. LastActor is not null, CurrentActor is not null - unhighlight LastActor, highlight CurrentActor
	// E. LastActor is not null, CurrentActor is LastActor - do nothing

	if ( LastActor == nullptr )
	{
		if (CurrentActor != nullptr)
		{
			// Case B
			CurrentActor->HighlightActor();
		}
		else
		{
			// Case A - both null, do nothing 
		}
	}
	else // LastActor valid
	{
		if (CurrentActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else // Both actors valid
		{
			// Case D
			if ( LastActor != CurrentActor )
			{
				LastActor->UnHighlightActor();
				CurrentActor->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
}
