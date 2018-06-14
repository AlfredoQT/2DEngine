#pragma once

#include "FSMState.h"

class COGFSM;

class FSMShotgunTurretState : public FSMState
{
public:

	FSMShotgunTurretState(COGFSM* pFSM);

	virtual void OnEnter() override;
	virtual void Update() override;
	virtual void OnExit() override;

};
