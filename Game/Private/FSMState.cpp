#include "..\Public\FSMState.h"
#include "..\Public\COG\COGFSM.h"

FSMState::FSMState(COGFSM * pFSM)
	: mFSM(pFSM)
{
}

FSMState::~FSMState()
{
}
