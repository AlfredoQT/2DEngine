#pragma once

#include "Component.h"

class COGFSM;
class COGLineShape;
class COGTransform;
class GameObject;
class IWeapon;

class COGTurret : public Component
{
public:

	COGTurret(GameObject* pGO);

	// Just in case I want many
	static std::vector<COGTurret*> turretComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	// This should be called every frame
	virtual void Update();

	// This will be modified by each state
	void SetWeaponIndex(int newWeapon);

	IWeapon* GetCurrentWeapon();

private:

	// The state machine of the turret
	COGFSM* mFSM;

	// This thing will dictate the state of the turret
	int mCurrentWeapon;

	std::vector<IWeapon*> mWeapons;

	COGLineShape* mLineShape;
	COGTransform* mTransform;

	const float TURRET_LENGTH = 40.0f;

};
