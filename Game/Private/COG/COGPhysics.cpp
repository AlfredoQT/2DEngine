#include "..\..\Public\COG\COGPhysics.h"
#include "..\..\Public\IPhysicsCollisionEvent.h"
#include "..\..\Public\GameObject.h"
#include "..\..\Public\COG\COGTransform.h"
#include "Engine\Public\Core\Time.h"

// The components
std::vector<COGPhysics*> COGPhysics::physicsComponents;

COGPhysics::COGPhysics(GameObject * pGO)
	: Component(pGO)
	, mRadius(0.0f)
	, mVelocity()
	, mGenerateCollisionEvents(false)
{
}

void COGPhysics::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>();
	AddToComponentVector(physicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(physicsComponents);
}

float & COGPhysics::GetRadius()
{
	return mRadius;
}

void COGPhysics::RegisterCollisionEvent(IPhysicsCollisionEvent * collisionEvent)
{
	mCollisionEvents.push_back(collisionEvent);
}

void COGPhysics::Simulate()
{
	// Move the rigid body
	Vector2& position = mTransform->GetPosition();
	position = position + Vector2(mVelocity.x, mVelocity.y) * Time::deltaTime;

	// Collisions
	if (mGenerateCollisionEvents)
	{
		// Iterate through the physics
		for (COGPhysics* physicsOther : COGPhysics::physicsComponents)
		{
			// Just in case
			if (physicsOther != nullptr)
			{
				// Don't collide with self
				if (physicsOther == this)
				{
					return;
				}

				if (IsColliding(physicsOther))
				{
					// The collision event handlers
					for (IPhysicsCollisionEvent* collisionEvent : mCollisionEvents)
					{
						collisionEvent->OnCollision(this, physicsOther);
					}
				}
			}
		}
	}
}

void COGPhysics::SetGenerateCollisionEvents(bool bGenerateCollisionEvents)
{
	mGenerateCollisionEvents = bGenerateCollisionEvents;
}

Vector2 & COGPhysics::GetVelocity()
{
	return mVelocity;
}

bool COGPhysics::IsColliding(COGPhysics * pOther)
{
	// Just in case
	if (pOther != nullptr)
	{
		// Other's position in the world
		Vector2 otherPosition = pOther->mTransform->GetPosition();

		// Check collision
		bool colliding = (otherPosition - mTransform->GetPosition()).SizeSquared() <= (pOther->mRadius + mRadius) * (pOther->mRadius + mRadius);

		// I do not need to store any collision information in this case
		return colliding;
	}
	return false;
}
