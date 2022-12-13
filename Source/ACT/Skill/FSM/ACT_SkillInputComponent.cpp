// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_SkillInputComponent.h"
#include "../ACT_Skill.h"

// Sets default values for this component's properties
UACT_SkillInputComponent::UACT_SkillInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UACT_SkillInputComponent::KeyInput(FKey Key)
{
	int32 keyHash = GetTypeHash(Key.GetFName());
	if (SkillsMap.Num() > 0) {
		for (auto& SkillMap: SkillsMap) {
			UACT_FSM* CurrentFSM = SkillMap.Value;
			bool check_a = CurrentFSM->Check(keyHash);
			if (check_a) {
				int32 currentId = CurrentFSM->CurrentState->StateId;
				//perform skill
				UACT_SkillItem* SkillToPerform = SkillMap.Key;
				AACT_Skill* NewSkill;
				UClass* SkillClass = SkillToPerform->Skill.Get();
				NewSkill = GetWorld()->SpawnActor<AACT_Skill>(SkillClass, OwnerCharacter->GetTransform());
				if (SkillToPerform && NewSkill) {
					NewSkill->Perform(OwnerCharacter, SkillToPerform, currentId);
					return;
				}
				if (CurrentFSM->Okay) {
					CurrentFSM->Reset();
				}
			}
		}
	}
}

// Called when the game starts
void UACT_SkillInputComponent::BeginPlay()
{
	Super::BeginPlay();
	check(this->GetOwner());
	OwnerCharacter = Cast<AACTCharacter>(this->GetOwner());
	ConstructFSMSkills();
	
}

bool UACT_SkillInputComponent::ConstructFSMSkill(UACT_SkillItem* skill_item)
{
	if (skill_item && skill_item->SkillInput.Num() > 0) {
		UACT_FSM* CurrentFSM = NewObject<UACT_FSM>(this);
		if (CurrentFSM) {
			for (int i = 0; i < skill_item->SkillInput.Num(); i++) {
				UACT_FSMState* NewState = NewObject<UACT_FSMState>(CurrentFSM);
				NewState->Init_FSMStateInfo(skill_item->SkillInput[i].Key, skill_item->SkillInput[i].InputTime, i, skill_item->SkillInput.Num() - 1);
				CurrentFSM->AddState(NewState);
			}
			SkillsMap.Add(skill_item, CurrentFSM);
			return true;
		}
		else return false;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Skill System Find Illegal Skill Input"));
		return false;
	}
}

void UACT_SkillInputComponent::ConstructFSMSkills()
{
	UACT_AssetManager& Manager = UACT_AssetManager::Get();
	TArray<FPrimaryAssetId> SkillIds;
	Manager.GetPrimaryAssetIdList(Manager.SkillType, SkillIds);
	for (auto& _id : SkillIds) {
		UACT_SkillItem* TempItem = Manager.GetPrimaryAssetObject<UACT_SkillItem>(_id);
		if (TempItem->Owner && this->GetOwner()->IsA(TempItem->Owner.Get())) {
			ConstructFSMSkill(TempItem);
		}
	}
}

