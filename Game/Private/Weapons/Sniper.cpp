#include "..\..\Public\Weapons\Sniper.h"
#include "..\..\Public\Input.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "..\..\Public\GameObjectFactory.h"

std::string Sniper::Type() const
{
	return "Sniper";
}

std::string Sniper::Instructions() const
{
	return "Press LMB to shoot a fast bullet";
}

void Sniper::Shoot(const Vector2& origin, const Vector2& dir)
{
	if (Input::Instance()->IsMouseButtonPressed(MouseButton::LEFT))
	{
		Debug::OutputLine("Sniper!!!");
		GameObjectFactory::Instance()->InstantiateBullet(origin, dir, 800.0f, "Player", "Enemy");
	}
}
