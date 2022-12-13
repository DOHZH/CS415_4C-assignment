// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../ACTCharacter.h"
#include "ACT_Skill.generated.h"

class UACT_SkillItem;
UCLASS()
class ACT_API AACT_Skill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AACT_Skill();

	//override blueprint and C++ both
	UFUNCTION(BlueprintCallable)
	void Perform(AACTCharacter* SkillOwner, UACT_SkillItem* SkillDataAsset, int32 id);
	//provide blueprint interface to override
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SkillProcess(AACTCharacter* SkillOwner, UACT_SkillItem* SkillDataAsset, int32 id);
	//provide C++ interface to override
	UFUNCTION()
	virtual void SkillProcess(AACTCharacter* SkillOwner, UACT_SkillItem* SkillDataAsset);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
