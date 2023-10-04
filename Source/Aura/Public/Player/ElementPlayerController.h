// Copywright MaxiMod Games 2023


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ElementPlayerController.generated.h"

class IEnemyInterface;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;


/**
 * 
 */
UCLASS()
class AURA_API AElementPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AElementPlayerController();
	virtual void PlayerTick( float DeltaTime ) override;
	
protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	UPROPERTY( EditAnywhere, Category = "Input" )
	TObjectPtr< UInputMappingContext > ElementContext;

	UPROPERTY( EditAnywhere, Category = "Input" )
	TObjectPtr< UInputAction > MoveAction;

	void Move( const FInputActionValue& InputActionValue );
	
	void CursorTrace();

	IEnemyInterface* LastActor;
	IEnemyInterface* CurrentActor;

	
};
