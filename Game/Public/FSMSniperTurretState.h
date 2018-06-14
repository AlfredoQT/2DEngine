#pragma once

#include "FSMState.h"

class COGFSM;

class FSMSniperTurretState : public FSMState
{
public:

	FSMSniperTurretState(COGFSM* pFSM);

	virtual void OnEnter() override;
	virtual void Update() override;
	virtual void OnExit() override;

};
