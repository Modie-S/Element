// Copyright MaxiMod Games 2023


#include "ElementCharacterBase.h"

// Sets default values
AElementCharacterBase::AElementCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AElementCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AElementCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

