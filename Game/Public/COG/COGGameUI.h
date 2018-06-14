#pragma once

#include "Component.h"
#include "Game\Public\GameObjectHandle.h"

class GameObject;

class COGGameUI : public Component
{
public:

	static COGGameUI* gameUIComponent;

	COGGameUI(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;

	// We need to have access to the turret component
	void SetTurret(const GameObjectHandle& pTurret);
	
	// To draw the stuff
	void ShowUI();

private:

	GameObjectHandle mTurret;

};
