// Copyright MaxiMod Games 2023


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ElementCharacterBase.generated.h"




UCLASS( Abstract )

class AURA_API AElementCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	AElementCharacterBase();

protected:

	virtual void BeginPlay() override;

	UPROPERTY( EditAnywhere, Category = "Combat" )
	TObjectPtr< USkeletalMeshComponent > Weapon;

};
