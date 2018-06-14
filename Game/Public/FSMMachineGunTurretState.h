#pragma once

#include "FSMState.h"

class COGFSM;

class FSMMachineGunTurretState : public FSMState
{
public:

	FSMMachineGunTurretState(COGFSM* pFSM);

	virtual void OnEnter() override;
	virtual void Update() override;
	virtual void OnExit() override;

};
