#include "..\Public\FSMShotgunTurretState.h"
#include "..\Public\COG\COGFSM.h"
#include "..\Public\COG\COGTurret.h"
#include "..\Public\GameObject.h"
#include "..\Public\Input.h"
#include "..\Public\FSMSniperTurretState.h"
#include "..\Public\FSMMachineGunTurretState.h"

FSMShotgunTurretState::FSMShotgunTurretState(COGFSM * pFSM)
	: FSMState(pFSM)
{
}

void FSMShotgunTurretState::OnEnter()
{
	// Set the weapon to be 1
	mFSM->GetGO()->FindComponent<COGTurret>()->SetWeaponIndex(1);
}

void FSMShotgunTurretState::Update()
{
	// Change the state based on input
	if (Input::Instance()->IsKeyPressed(KeyCode::Alpha1))
	{
		// Go to Sniper
		mFSM->Next(new FSMSniperTurretState(mFSM));
	}
	else if (Input::Instance()->IsKeyPressed(KeyCode::Alpha3))
	{
		// Go to MachineGun
		mFSM->Next(new FSMMachineGunTurretState(mFSM));
	}
}

void FSMShotgunTurretState::OnExit()
{
}
