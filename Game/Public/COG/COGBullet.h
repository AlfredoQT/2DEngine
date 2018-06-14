#pragma once

#include "Component.h"
#include "Game\Public\IPhysicsCollisionEvent.h"
#include <string>

class GameObject;
class COGPhysics;
class COGTransform;

// This will handle bullet collisions
class COGBullet : public Component, IPhysicsCollisionEvent
{
public:

	// It's really just for checking collisions with the walls
	static std::vector<COGBullet*> bulletComponents;

	COGBullet(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;

	// This is really the only one that will be called every frame
	void CheckWallCollisions();

	void SetTargetTag(std::string pTag);

	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther) override;

private:

	std::string mTargetTag;
	
	// To know where it currently is to delete itself on collision with walls
	COGTransform* mTransform;

	// To register self as collision listener
	COGPhysics* mPhysics;

};
