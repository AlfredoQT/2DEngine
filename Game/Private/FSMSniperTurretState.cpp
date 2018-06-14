#include "..\Public\FSMSniperTurretState.h"
#include "..\Public\COG\COGFSM.h"
#include "..\Public\COG\COGTurret.h"
#include "..\Public\GameObject.h"
#include "..\Public\Input.h"
#include "..\Public\FSMShotgunTurretState.h"
#include "..\Public\FSMMachineGunTurretState.h"

FSMSniperTurretState::FSMSniperTurretState(COGFSM * pFSM)
	: FSMState(pFSM)
{
}

void FSMSniperTurretState::OnEnter()
{
	// Set the weapon to be 0
	mFSM->GetGO()->FindComponent<COGTurret>()->SetWeaponIndex(0);
}

void FSMSniperTurretState::Update()
{
	// Change the state based on input
	if (Input::Instance()->IsKeyPressed(KeyCode::Alpha2))
	{
		// Go to Shotgun
		mFSM->Next(new FSMShotgunTurretState(mFSM));
	}
	else if (Input::Instance()->IsKeyPressed(KeyCode::Alpha3))
	{
		// Go to MachineGun
		mFSM->Next(new FSMMachineGunTurretState(mFSM));
	}
}

void FSMSniperTurretState::OnExit()
{
}
