#pragma once

#include "IWeapon.h"

struct Vector2;

class Shotgun : public IWeapon
{
public:

	virtual std::string Type() const override;

	virtual std::string Instructions() const override;

	virtual void Shoot(const Vector2& origin, const Vector2& dir) override;

};
