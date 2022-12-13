// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseItem/ACT_Item.h"
#include "../ACT_Type.h"
#include "../ACTCharacter.h"
#include "ACT_SkillItem.generated.h"

class AACT_Skill;
/**
 *
 */
UCLASS()
class ACT_API UACT_SkillItem : public UACT_Item
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName SkillName;

	//whether player learned this ability
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool Active = true;

	//skill's priority
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 SkillPriority = 0;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<FACT_InputStruct> SkillInput;

	//holder of this skill
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<AACTCharacter> Owner;

	//holder of this skill
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<AACT_Skill> Skill;
};
