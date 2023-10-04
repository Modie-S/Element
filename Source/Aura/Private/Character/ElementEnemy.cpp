// Copyright MaxiMod Games 2023

// This file's header
#include "Character/ElementEnemy.h"

// Unreal Engine 
#include "Aura/Aura.h"


AElementEnemy::AElementEnemy()
{
	GetMesh()->SetCollisionResponseToChannel( ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block );
}

void AElementEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth( true );
	GetMesh()->SetCustomDepthStencilValue( CUSTOM_DEPTH_RED );
}

void AElementEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth( false );
}
