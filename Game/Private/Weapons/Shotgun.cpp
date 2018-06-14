#include "..\..\Public\Weapons\Shotgun.h"
#include "..\..\Public\Input.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "..\..\Public\GameObjectFactory.h"
#include "Game\Public\FMath.h"

std::string Shotgun::Type() const
{
	return "Shotgun";
}

std::string Shotgun::Instructions() const
{
	return "Press LMB to shoot three bullets";
}

void Shotgun::Shoot(const Vector2& origin, const Vector2& dir)
{
	if (Input::Instance()->IsMouseButtonPressed(MouseButton::LEFT))
	{
		Debug::OutputLine("Shotgun!!!");

		// Angle
		float angle = FMath::Atan2(dir.y, dir.x);

		// Three guys, just 20 degrees
		GameObjectFactory::Instance()->InstantiateBullet(origin, Vector2(FMath::Cos(angle - 20.0f * FMath::Deg2Rad), FMath::Sin(angle - 20.0f * FMath::Deg2Rad)), 300.0f, "Player", "Enemy");
		GameObjectFactory::Instance()->InstantiateBullet(origin, dir, 300.0f, "Player", "Enemy");
		GameObjectFactory::Instance()->InstantiateBullet(origin, Vector2(FMath::Cos(angle + 20.0f * FMath::Deg2Rad), FMath::Sin(angle + 20.0f * FMath::Deg2Rad)), 300.0f, "Player", "Enemy");
	}
}
