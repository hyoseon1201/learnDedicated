// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CCharacter.generated.h"

UCLASS()
class CRUNCH_API ACCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACCharacter();
	void ServerSideInit();
	void ClientSideInit();
	bool IsLocallyControlledByPlayer() const;

	// only called on the server
	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**************************************************************************/
	/*                            Gameplay Ability                            */
	/**************************************************************************/
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Gameplay Ability")
	class UCAbilitySystemComponent* CAbilitySystemComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Gameplay Ability")
	class UCAttributeSet* CAttributeSet;

	/**************************************************************************/
	/*                                  UI                                    */
	/**************************************************************************/
private:
	void ConfigureOverHeadStatsWidget();
	void UpdateHeadGaugeVisibility();

	UPROPERTY(VisibleDefaultsOnly, Category = "UI")
	class UWidgetComponent* OverHeadWidgetComponent;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	float HeadStatsGaugeVisibilityCheckUpdateGap = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	float HeadStatsGaugeVisibilityRangeSquared = 1000000.f;

	FTimerHandle HeadStatGaugeVisibilityUpdateTimerHandle;
};
