// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/GameplayWidget.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Widget/ValueGauge.h"
#include "GAS/CAttributeSet.h"
#include "GAS/CAbilitySystemComponent.h"
#include "Widget/AbilityListView.h"

void UGameplayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OwnerAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwningPlayerPawn());

	if (OwnerAbilitySystemComponent)
	{
		HealthBar->SetAndBoundToGameplayAttribute(OwnerAbilitySystemComponent, UCAttributeSet::GetHealthAttribute(), UCAttributeSet::GetMaxHealthAttribute());
		ManaBar->SetAndBoundToGameplayAttribute(OwnerAbilitySystemComponent, UCAttributeSet::GetManaAttribute(), UCAttributeSet::GetMaxManaAttribute());
	}
}

void UGameplayWidget::ConfigureAbilities(const TMap<ECAbilityInputID, TSubclassOf<class UGameplayAbility>>& Abilities)
{
	AbilityListView->ConfigureAbilities(Abilities);
}
