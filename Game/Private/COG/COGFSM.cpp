#include "..\..\Public\COG\COGFSM.h"
#include "..\..\Public\GameObject.h"
#include "..\..\Public\FSMState.h"

std::vector<COGFSM*> COGFSM::fsmComponents;

COGFSM::COGFSM(GameObject * pGO)
	: Component(pGO)
	, mCurrent(nullptr)
	, mNext(nullptr)
{
}

COGFSM::~COGFSM()
{
}

void COGFSM::Initialize()
{
	AddToComponentVector(fsmComponents);
}

void COGFSM::Destroy()
{
	RemoveFromComponentVector(fsmComponents);
}

// Should be called only once, the first time
void COGFSM::SetInitial(FSMState * pState)
{
	mCurrent = pState;
}

void COGFSM::Next(FSMState * pState)
{
	// I'm not sure if this will happen because we are always setting it to a nullptr when we get a new state on Update
	if (mNext != nullptr)
	{
		delete mNext;
	}
	// Move to the next state
	mNext = pState;
}

void COGFSM::Update()
{
	// In this case, a new state has been set
	if (mNext != nullptr)
	{
		// Exit the current state
		mCurrent->OnExit();

		// Get rid of it
		delete mCurrent;

		// Assign the new state and enter
		mCurrent = mNext;
		mCurrent->OnEnter();

		// Prepare the next state holder for the Next call
		mNext = nullptr;
	}

	// A normal update on the state
	mCurrent->Update();
}
