// Copyright MaxiMod Games 2023


#pragma once

#include "CoreMinimal.h"
#include "Character/ElementCharacterBase.h"
#include "ElementEnemy.generated.h"
#include "Interaction/EnemyInterface.h"




/**
 * 
 */
UCLASS()
class AURA_API AElementEnemy : public AElementCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
};
