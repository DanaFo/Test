// Fill out your copyright notice in the Description page of Project Settings.


#include "TestAttributeSet.h"

#include "Net/UnrealNetwork.h"
#include "Runtime/Core/Tests/Containers/TestUtils.h"

UTestAttributeSet::UTestAttributeSet()
{
}

void UTestAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, MoveSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTestAttributeSet, BaseMoveSpeed, COND_None, REPNOTIFY_Always);
}

void UTestAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, Health, OldHealth);
}

void UTestAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, MaxHealth, OldMaxHealth);

}

void UTestAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, MoveSpeed, OldMoveSpeed);

}

void UTestAttributeSet::OnRep_BaseMoveSpeed(const FGameplayAttributeData& OldBaseMoveSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTestAttributeSet, BaseMoveSpeed, OldBaseMoveSpeed);

}
