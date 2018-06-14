#include "..\..\Public\COG\COGBullet.h"
#include "Game\Public\COG\COGPhysics.h"
#include "Game\Public\COG\COGTransform.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"
#include "Game\Public\World.h"
#include "Game\Public\COG\COGHealth.h"
#include <string>

// Components
std::vector<COGBullet*> COGBullet::bulletComponents;

COGBullet::COGBullet(GameObject * pGO)
	: Component(pGO)
{
}

void COGBullet::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>();
	mPhysics = mGO->FindComponent<COGPhysics>();
	
	// Register self as collision event listener
	mPhysics->RegisterCollisionEvent(this);

	AddToComponentVector(bulletComponents);
}

void COGBullet::Destroy()
{
	RemoveFromComponentVector(bulletComponents);
}

void COGBullet::CheckWallCollisions()
{
	// I know this so hardcoded
	if (mTransform->GetPosition().x <= 0.0f
		|| mTransform->GetPosition().x >= 800.0f
		|| mTransform->GetPosition().y <= 0.0f
		|| mTransform->GetPosition().y >= 600.0f)
	{
		// Tell the world to destroy me
		mGO->GetWorld()->Delete(mGO->GetHandle());
	}
}

void COGBullet::SetTargetTag(std::string pTag)
{
	mTargetTag = pTag;
}

void COGBullet::OnCollision(COGPhysics * pMe, COGPhysics * pOther)
{
	// Check collisions
	if (pOther != nullptr)
	{
		GameObject* otherGO = pOther->GetGO();
		
		if (otherGO != nullptr)
		{
			// Compare the tags
			if (mTargetTag.compare(otherGO->GetTag()) == 0)
			{
				// Get health component from other
				COGHealth* health = otherGO->FindComponent<COGHealth>();
				
				// Take damage in this case
				if (health != nullptr)
				{
					health->ReceiveDamage(5.0f);
				}
				else
				{
					otherGO->GetWorld()->Delete(otherGO->GetHandle());
				}
				// Destroy self
				if (mGO != nullptr)
				{
					mGO->GetWorld()->Delete(mGO->GetHandle());
				}
			}
		}
	}
}
