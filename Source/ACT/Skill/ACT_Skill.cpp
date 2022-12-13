// Fill out your copyright notice in the Description page of Project Settings.

#include "ACT_Skill.h"

// Sets default values
AACT_Skill::AACT_Skill()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AACT_Skill::Perform(AACTCharacter* SkillOwner, UACT_SkillItem* SkillDataAsset, int32 id)
{
	SkillProcess(SkillOwner, SkillDataAsset);
	BP_SkillProcess(SkillOwner, SkillDataAsset, id);
}

void AACT_Skill::SkillProcess(AACTCharacter* SkillOwner, UACT_SkillItem* SkillDataAsset)
{

}

// Called when the game starts or when spawned
void AACT_Skill::BeginPlay()
{
	Super::BeginPlay();
}
