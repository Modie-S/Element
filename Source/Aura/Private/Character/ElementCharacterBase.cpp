// Copyright MaxiMod Games 2023




#include "Character/ElementCharacterBase.h"

AElementCharacterBase::AElementCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject< USkeletalMeshComponent >( "Weapon" );
	Weapon->SetupAttachment( GetMesh(), FName( "WeaponHandSocket" ) );
	Weapon->SetCollisionEnabled( ECollisionEnabled::NoCollision );
}

void AElementCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}