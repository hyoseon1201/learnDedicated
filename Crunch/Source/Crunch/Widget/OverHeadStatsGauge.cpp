// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/OverHeadStatsGauge.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Widget/ValueGauge.h"
#include "GAS/CAttributeSet.h"

void UOverHeadStatsGauge::ConfigureWithASC(UAbilitySystemComponent* AbilitySystemComponent)
{
	if (AbilitySystemComponent)
	{
		HealthBar->SetAndBoundToGameplayAttribute(AbilitySystemComponent, UCAttributeSet::GetHealthAttribute(), UCAttributeSet::GetMaxHealthAttribute());
		ManaBar->SetAndBoundToGameplayAttribute(AbilitySystemComponent, UCAttributeSet::GetManaAttribute(), UCAttributeSet::GetMaxManaAttribute());
	}
}
