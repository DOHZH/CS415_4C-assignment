// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_FSM.h"

bool UACT_FSM::AddState(UACT_FSMState* StateToAdd)
{
	if (StateToAdd && !FSMStatesMap.Contains(StateToAdd->StateId)) {
		FSMStatesMap.Add(StateToAdd->StateId, StateToAdd);
		return true;
	}
	return false;
}

bool UACT_FSM::ChnageState(uint32 state_id)
{
	if (FSMStatesMap.Contains(state_id)) {
		UACT_FSMState* state_from_id = FSMStatesMap[state_id];
		if (state_from_id) {
			CurrentState = state_from_id;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(CurrentState->StateId));
			return true;
		}
		return false;
	}
	return false;
}

void UACT_FSM::SetTimer(float TimeDelay)
{
	if (GetWorld()) {
		//settimer: false means when we finish executing delay and callback, whether we continue execute them in a loop; 
		//the last param means how long delay exists before we start the formal loop of delay. -1.0f means we don't need pre-delay
		//0 will lead infinite loop, so we need to avoid 0 and use 0.000001
		GetWorld()->GetTimerManager().SetTimer(ResetTimer, this, &UACT_FSM::Reset, (TimeDelay == 0) ? 0.0000001f : TimeDelay, false, -1.f);
	}
}

void UACT_FSM::Reset()
{
	if (GetWorld()) {
		Okay = false;
		GetWorld()->GetTimerManager().ClearTimer(ResetTimer);
		ChnageState(0);
	}
}

bool UACT_FSM::Check(int32 InputHash)
{
	if (CurrentState == nullptr && FSMStatesMap[0]) {
		Reset();
		return false;
	} 
	if (CurrentState && InputHash == CurrentState->KeyID) {
		SetTimer(CurrentState->Time);
		if (CurrentState->StateId == CurrentState->StateMaxId) {
			Okay = true;
			ChnageState(0);
		}
		else {
			ChnageState(CurrentState->StateId + 1);
		}
		return true;
	}
	else {
		Reset();
		return false;
	}
}
