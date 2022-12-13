// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACT_AttackMotion.h"
#include "ACT_ComboClip.generated.h"

/**
 * 
 */
UCLASS()
class ACT_API UACT_ComboClip : public UACT_AttackMotion
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	bool Branch = false;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UACT_ComboClip* NextCombo;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UACT_ComboClip* BranchCombo;
};
