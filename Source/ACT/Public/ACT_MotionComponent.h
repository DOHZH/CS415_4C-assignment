// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACT_ComboTree.h"
#include "ACT_MotionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACT_API UACT_MotionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACT_MotionComponent();
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UACT_ComboTree* Combomtree;
	UPROPERTY()
	bool use_branch;
	UFUNCTION()
	UACT_ComboClip* GetAttackMotion(int node_index);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
};
