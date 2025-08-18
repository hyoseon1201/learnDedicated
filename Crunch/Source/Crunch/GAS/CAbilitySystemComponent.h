// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GAS/CGameplayAbilityTypes.h"
#include "GameplayEffectTypes.h"
#include "CAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class CRUNCH_API UCAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	UCAbilitySystemComponent();
	void ServerSideInit();
	void InitializeBaseAttributes();

	void ApplyFullStatEffect();

	// Get the Abilities that is unique for the avatar actor, this do not include generic/basic ones
	const TMap<ECAbilityInputID, TSubclassOf<UGameplayAbility>>& GetAbilities() const;

	bool IsAtMaxLevel() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	TMap<ECAbilityInputID, TSubclassOf<UGameplayAbility>> Abilities;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	TMap<ECAbilityInputID, TSubclassOf<UGameplayAbility>> BasicAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	class UPA_AbilitySystemGenerics* AbilitySystemGenerics;

	void ApplyInitialEffects();
	void GiveInitialAbilities();
	void AuthApplyGameplayEffect(TSubclassOf<UGameplayEffect> GameplayEffect, int Level = 1);
	void HealthUpdated(const FOnAttributeChangeData& ChangeData);
	void ManaUpdated(const FOnAttributeChangeData& ChangeData);
	void ExperienceUpdated(const FOnAttributeChangeData& ChangeData);
};
