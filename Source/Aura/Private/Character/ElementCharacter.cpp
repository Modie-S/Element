// Copyright MaxiMod Games 2023


// This file's header
#include "Character/ElementCharacter.h"

// Unreal Engine
#include "GameFramework/CharacterMovementComponent.h"

AElementCharacter::AElementCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator( 0.f, 400.f, 0.f );
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;


}
