#pragma once

#include "IWeapon.h"

struct Vector2;

class MachineGun : public IWeapon
{
public:

	MachineGun();

	virtual std::string Type() const override;

	virtual std::string Instructions() const override;

	virtual void Shoot(const Vector2& origin, const Vector2& dir) override;

private:

	// The interval at which bullets are spawned
	const float TIME_BETWEEN_SHOTS = 0.2f;

	float timeForNextShot;

};
