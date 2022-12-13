// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_FSMState.h"

void UACT_FSMState::Init_FSMStateInfo(int32 _key_id, float _time, int32 _state_id, int32 _state_max_id)
{
	KeyID = _key_id;
	Time = _time;
	StateId = _state_id;
	StateMaxId = _state_max_id;
}

void UACT_FSMState::Init_FSMStateInfo(FKey _key_code, float _time, int32 _state_id, int32 _state_max_id)
{
	KeyID = GetTypeHash(_key_code.GetFName());
	Time = _time;
	StateId = _state_id;
	StateMaxId = _state_max_id;
}
