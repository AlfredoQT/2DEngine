#pragma once

class COGFSM;

// A simple abstract class to define a state from a state machine
class FSMState
{
public:

	FSMState(COGFSM* pFSM);
	virtual ~FSMState();

	virtual void OnEnter() = 0;
	virtual void Update() = 0;
	virtual void OnExit() = 0;

protected:

	COGFSM * mFSM;

};
