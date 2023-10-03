// Copywright MaxiMod Games 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ElementPlayerController.generated.h"


class UInputMappingContext;
/**
 * 
 */
UCLASS()
class AURA_API AElementPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AElementPlayerController();
	
protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY( EditAnywhere, Category="Input" )
	TObjectPtr< UInputMappingContext > ElementContext;
	
};
