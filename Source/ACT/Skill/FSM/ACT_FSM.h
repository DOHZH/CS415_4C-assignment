// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ACT_FSMState.h"
#include "TimerManager.h"
#include "ACT_FSM.generated.h"

/**
 * FSM: store FSMState to ensure combo
 */
UCLASS()
class ACT_API UACT_FSM : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<int32, UACT_FSMState*> FSMStatesMap;
	UPROPERTY()
	UACT_FSMState* CurrentState;
	UPROPERTY()
	bool Okay = false;// check combo whether be finished

public:
	FTimerHandle ResetTimer;
	//add state node
	bool AddState(UACT_FSMState* StateToAdd);
	//change state to target, indexing by id
	bool ChnageState(uint32 state_id);
	//use timer to decide new input whether go to next state
	void SetTimer(float TimeDelay);
	//Timer_handler
	void Reset();

	bool Check(int32 InputHash);

};
