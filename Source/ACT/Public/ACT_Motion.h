// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseItem/ACT_Item.h"
#include "Animation/AnimMontage.h"
#include "ACT_Motion.generated.h"

/**
 *
 */
UCLASS()
class ACT_API UACT_Motion : public UACT_Item
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimMontage* MontageToPlay;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float PlayerRate = 1.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float StartingPosition = 0.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StartingSection = FName("None");

};
