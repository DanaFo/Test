// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacterPC.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ATestCharacterPC::ATestCharacterPC()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
}
	
	void ATestCharacter::PossessedBy(AController* NewController)
	{
		Super::PossessedBy(NewController);

		if (AbilitySystemComponent)
		{
			AbilitySystemComponent->InitAbilityActorInfo(this, this);

			InitializeAttributes();
			GiveDefaultAbilities();
		}
	}

	void ATestCharacter::OnRep_PlayerState()
	{
		Super::OnRep_PlayerState();

		if (AbilitySystemComponent)
			AbilitySystemComponent->InitAbilityActorInfo(this, this);

		InitializeAttributes();
	
	}







