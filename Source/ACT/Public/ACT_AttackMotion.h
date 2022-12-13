// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACT_Motion.h"
#include "../ACT_Type.h"
#include "ACT_AttackMotion.generated.h"

/**
 * 
 */
UCLASS()
class ACT_API UACT_AttackMotion : public UACT_Motion
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FACT_AttackMotionStruct AttackMotionData;
};
