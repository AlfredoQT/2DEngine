#include "..\Public\FSMMachineGunTurretState.h"
#include "..\Public\COG\COGFSM.h"
#include "..\Public\COG\COGTurret.h"
#include "..\Public\GameObject.h"
#include "..\Public\Input.h"
#include "..\Public\FSMSniperTurretState.h"
#include "..\Public\FSMShotgunTurretState.h"

FSMMachineGunTurretState::FSMMachineGunTurretState(COGFSM * pFSM)
	: FSMState(pFSM)
{
}

void FSMMachineGunTurretState::OnEnter()
{
	// Set the weapon to be 2
	mFSM->GetGO()->FindComponent<COGTurret>()->SetWeaponIndex(2);
}

void FSMMachineGunTurretState::Update()
{
	// Change the state based on input
	if (Input::Instance()->IsKeyPressed(KeyCode::Alpha1))
	{
		// Go to Sniper
		mFSM->Next(new FSMSniperTurretState(mFSM));
	}
	else if (Input::Instance()->IsKeyPressed(KeyCode::Alpha2))
	{
		// Go to Shotgun
		mFSM->Next(new FSMShotgunTurretState(mFSM));
	}
}

void FSMMachineGunTurretState::OnExit()
{
}
