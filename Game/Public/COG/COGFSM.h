#pragma once

#include "Component.h"

class GameObject;
class FSMState;

class COGFSM : public Component
{
public:

	static std::vector<COGFSM*> fsmComponents;

	COGFSM(GameObject* pGO);
	~COGFSM();

	virtual void Initialize() override;
	virtual void Destroy() override;

	void SetInitial(FSMState* pState);
	void Next(FSMState* pState);

	// To update the current state
	void Update();

private:

	FSMState* mCurrent;
	FSMState* mNext;

};
