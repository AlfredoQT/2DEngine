#include "..\..\Public\COG\COGTurret.h"
#include "..\..\Public\GameObject.h"
#include "..\..\Public\COG\COGFSM.h"
#include "..\..\Public\Weapons\MachineGun.h"
#include "..\..\Public\Weapons\Sniper.h"
#include "..\..\Public\Weapons\Shotgun.h"
#include "..\..\Public\COG\COGTransform.h"
#include "..\..\Public\FSMSniperTurretState.h"
#include "..\..\Public\COG\COGTransform.h"
#include "..\..\Public\COG\COGLineShape.h"
#include "Engine\Public\Core\FMath.h"
#include "..\..\Public\Input.h"
#include "Engine\Public\Utils\Debug.h"

// The components
std::vector<COGTurret*> COGTurret::turretComponents;

COGTurret::COGTurret(GameObject * pGO)
	: Component(pGO)
	, mCurrentWeapon(0)
{
	// This is the default weapon
	mWeapons.push_back(new Sniper());
	mWeapons.push_back(new Shotgun());
	mWeapons.push_back(new MachineGun());
}

void COGTurret::Initialize()
{
	mFSM = mGO->FindComponent<COGFSM>();
	// The initial state
	mFSM->SetInitial(new FSMSniperTurretState(mFSM));

	mTransform = mGO->FindComponent<COGTransform>();
	mLineShape = mGO->FindComponent<COGLineShape>();

	// Add the two points to the line
	mLineShape->AddPoint(mTransform->GetPosition());
	mLineShape->AddPoint(mTransform->GetPosition());

	AddToComponentVector(turretComponents);
}

void COGTurret::Destroy()
{
	RemoveFromComponentVector(turretComponents);
}

void COGTurret::Update()
{
	// Calculate a vector from the origin to the mouse, to create the turret
	Vector2 toMouse = Input::Instance()->GetMousePosition() - mTransform->GetPosition();

	// The angle with respect to x axis
	float toMouseAngle = FMath::Atan2(toMouse.y, toMouse.x);

	// Clamp the angle
	toMouseAngle = FMath::Clamp(toMouseAngle, -FMath::PI / 4.0f, FMath::PI / 4.0f);

	// The muzzle of the turret
	Vector2 muzzle = mTransform->GetPosition() + Vector2(FMath::Cos(toMouseAngle), FMath::Sin(toMouseAngle)) * TURRET_LENGTH;

	// Update the line shape point
	mLineShape->SetPoint(1, mTransform->GetPosition() + Vector2(FMath::Cos(toMouseAngle), FMath::Sin(toMouseAngle)) * TURRET_LENGTH);

	// Tell the weapon to shoot itself
	mWeapons[mCurrentWeapon]->Shoot(muzzle, Vector2(FMath::Cos(toMouseAngle), FMath::Sin(toMouseAngle)));
}

void COGTurret::SetWeaponIndex(int newWeapon)
{
	// Set it to the default if it is out of range
	if (newWeapon < 0 || newWeapon >= mWeapons.size())
	{
		mCurrentWeapon = 0;
		return;
	}
	mCurrentWeapon = newWeapon;
}

IWeapon* COGTurret::GetCurrentWeapon()
{
	return mWeapons[mCurrentWeapon];
}
