#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Vector2.h"

class IPhysicsCollisionEvent;
class GameObject;
class COGTransform;

class COGPhysics : public Component
{
public:

	static std::vector<COGPhysics*> physicsComponents;

	COGPhysics(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;

	float& GetRadius();

	void RegisterCollisionEvent(IPhysicsCollisionEvent* collisionEvent);

	void Simulate();

	void SetGenerateCollisionEvents(bool bGenerateCollisionEvents);

	Vector2& GetVelocity();

private:

	std::vector<IPhysicsCollisionEvent*> mCollisionEvents;

	// Size of collider
	float mRadius;

	// Whether to check collisions
	bool mGenerateCollisionEvents;

	// The transform to keep the position in the world of the game object
	COGTransform* mTransform;

	// Hold the velocity of the rigid body
	Vector2 mVelocity;

	// Check collisions with another rigid body
	bool IsColliding(COGPhysics* pOther);

};
