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
	
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilties();
	
	UPROPERTY()
	class UTestAttributeSet* AttributeSet;

	// default gameplay attribute value setter
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilties")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// the list of default abilities for base character
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilties")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;
	
	// set initial values for stats/attributes
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Attributes")
	int MaxHealth = 100;
	
	
private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;


};

