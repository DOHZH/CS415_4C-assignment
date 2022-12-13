// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_MotionComponent.h"
#include "ACT_ComboClip.h"

// Sets default values for this component's properties
UACT_MotionComponent::UACT_MotionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


UACT_ComboClip* UACT_MotionComponent::GetAttackMotion(int node_index)
{
	UACT_ComboClip* nowClip = Combomtree->FirstComboClip;
	UACT_ComboClip* newBranch = nowClip->BranchCombo;
	for (int i = 0; i < node_index; i++) {
		nowClip = nowClip->NextCombo;
		newBranch = nowClip->BranchCombo;
	}
	if (newBranch != nullptr && use_branch) {
		return newBranch;
	}
	else {
		return nowClip;
	}

}

// Called when the game starts
void UACT_MotionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

