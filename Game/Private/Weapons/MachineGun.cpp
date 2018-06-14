#include "..\..\Public\Weapons\MachineGun.h"
#include "..\..\Public\Input.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Engine\Public\Core\Time.h"
#include "..\..\Public\GameObjectFactory.h"

MachineGun::MachineGun()
	: timeForNextShot(TIME_BETWEEN_SHOTS)
{
}

std::string MachineGun::Type() const
{
	return "Machine Gun";
}

std::string MachineGun::Instructions() const
{
	return "Hold LMB to shoot many bullets!";
}

void MachineGun::Shoot(const Vector2& origin, const Vector2& dir)
{
	// Increase the timer!
	timeForNextShot = timeForNextShot < TIME_BETWEEN_SHOTS ? timeForNextShot + Time::deltaTime : TIME_BETWEEN_SHOTS;

	// This one shoots a little different :)
	if (Input::Instance()->IsMouseButtonDown(MouseButton::LEFT))
	{	
		// Check if it is time to spawn the bullet
		if (timeForNextShot >= TIME_BETWEEN_SHOTS)
		{
			Debug::OutputLine("MachineGun!!!");

			// Spawn the bullet
			GameObjectFactory::Instance()->InstantiateBullet(origin, dir, 650.0f, "Player", "Enemy");

			// Reset the timer
			timeForNextShot = 0.0f;
		}
	}
}
