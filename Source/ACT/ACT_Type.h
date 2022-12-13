// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimationAsset.h"
#include "ACT_Type.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EACT_PropertyName : uint8
{
	EpropertyHp UMETA(DisplayName = "HP"),
	EpropertyExp UMETA(DisplayName = "EXP"),
	EpropertyLevel UMETA(DisplayName = "Level")
};

USTRUCT(BlueprintType)
struct FACT_PropertyValue {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Min;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Current;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Max;
};

USTRUCT(BlueprintType)
struct FACT_InputStruct {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FKey Key;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float InputTime = .5f;
};

USTRUCT(BlueprintType)
struct FACT_AttackMotionStruct
{
	GENERATED_USTRUCT_BODY()
};
