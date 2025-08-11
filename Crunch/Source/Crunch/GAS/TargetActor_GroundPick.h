// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "TargetActor_GroundPick.generated.h"

/**
 * 
 */
UCLASS()
class CRUNCH_API ATargetActor_GroundPick : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()
	
public:
	ATargetActor_GroundPick();

	virtual void ConfirmTargetingAndContinue() override;
	void SetTargetAreaRadius(float NewRadius);
	void SetTargetOptions(bool bTargetFriendly, bool bTargetEnemy);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Targetting")
	float TargetTraceRange = 2000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Targetting")
	float TargetAreaRadius = 300.f;

	bool bShouldTargetEnemy = true;
	bool bShouldTargetFriendly = false;

	virtual void Tick(float DeltaTime) override;

	FVector GetTargetPoint() const;
};
