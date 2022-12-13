// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ACT_FSMState.generated.h"

/**
 * This is FSM node containing time and input
 */
UCLASS()
class ACT_API UACT_FSMState : public UObject
{
	GENERATED_BODY()

public:
	//Key id
	//in unreal, we use FKey to store keyboard(or other controlers key) value; different key will have different id (hash); this section, to make program has
	//more scalability, we use int32 to store key directly (uint32 is a type used by FKey representing hash id of key
	uint32 KeyID;
	float Time;

	//check whether this node is last node in combo
	int32 StateId;//this node index
	int32 StateMaxId;//the combo where the node is in last node index

	void Init_FSMStateInfo(int32 _key_id, float _time, int32 _state_id, int32 _state_max_id);
	void Init_FSMStateInfo(FKey _key_code, float _time, int32 _state_id, int32 _state_max_id);
};
