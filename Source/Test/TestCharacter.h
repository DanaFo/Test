// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "TestAttributeSet.h"

#include "TestCharacter.generated.h"

UCLASS(config=Game)
class ATestCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATestCharacter();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilities();

	
	UPROPERTY()
	const UTestAttributeSet* AttributeSet;

	// default gameplay attribute value setter
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilties")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// the list of default abilities for base character
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilties")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetMoveSpeed() const;
	
	// set initial values for stats/attributes
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Attributes")
	int MaxHealth = 200;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Attributes")
	int BaseHealth = 100;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Attributes")
	int Health = 100;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Attributes")
	float MoveSpeed = 100;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Attributes")
	float BaseMoveSpeed = 100;
	

protected:


};

// https://github.com/Pantong51/GASContent/blob/master/Tutorial_Attribute_Delegates.md
