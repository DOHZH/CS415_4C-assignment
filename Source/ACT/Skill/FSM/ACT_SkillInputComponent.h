// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../ACT_SkillItem.h"
#include "ACT_FSM.h"
#include "../../BaseItem/ACT_AssetManager.h"
#include "ACT_SkillInputComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class ACT_API UACT_SkillInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACT_SkillInputComponent();

	//build Skill and attach it to a FSM
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TMap<UACT_SkillItem*, UACT_FSM*> SkillsMap;
	
	//Character
	UPROPERTY(BlueprintReadOnly)
	AACTCharacter* OwnerCharacter;

	//get key code
	UFUNCTION()
	void KeyInput(FKey Key);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//construct FSM for specified SkillItem
	UFUNCTION()
	bool ConstructFSMSkill(UACT_SkillItem* skill_item);
	//construct FSMs for all SkillItems
	UFUNCTION()
	void ConstructFSMSkills();
};
