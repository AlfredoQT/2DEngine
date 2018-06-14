#pragma once

#include <string>

struct Vector2;

// Just a simple interface for the weapons of the turret
class IWeapon
{
public:

	virtual std::string Type() const = 0;

	virtual std::string Instructions() const = 0;

	// The muzzle and the direction
	virtual void Shoot(const Vector2& origin, const Vector2& dir) = 0;
};
