#pragma once

class COGPhysics;

// An interface for collision events
class IPhysicsCollisionEvent
{
public:

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther) = 0;

};
