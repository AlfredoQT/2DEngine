#pragma once

#include "Engine\Public\Core\Types\Vector2.h"

// Hold collision information
struct CollisionInfo
{
	// Hold the normal of the collision
	Vector2 mNormal;

	// How much did it went through
	Vector2 mDepth;
};
