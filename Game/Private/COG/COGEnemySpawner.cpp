#include "..\..\Public\COG\COGEnemySpawner.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\Random.h"
#include "Game\Public\GameObjectFactory.h"
#include "Engine\Public\Core\Time.h"
#include "Game\Public\COG\COGTransform.h"

COGEnemySpawner* COGEnemySpawner::spawnerComponent = nullptr;

COGEnemySpawner::COGEnemySpawner(GameObject * pGO)
	: Component(pGO)
	, mTimeForNextSpawn(0.0f)
	, mTimeBetweenSpawns(0.0f)
{
}

void COGEnemySpawner::Initialize()
{
	spawnerComponent = this;
	mTimeBetweenSpawns = Random::Instance()->NextFloat(0.7f, 1.5f);
}

void COGEnemySpawner::SpawnEnemies()
{
	// Check if the target is valid
	if (!mTarget.IsValid())
	{
		return;
	}

	// Increase the timer
	mTimeForNextSpawn += Time::deltaTime;

	// Time to spawn
	if (mTimeForNextSpawn >= mTimeBetweenSpawns)
	{
		// Random initial position
		Vector2 origin = Vector2(750.0f, Random::Instance()->NextFloat(50.0f, 550.0f));

		// Store the direction
		Vector2 dir;

		// Try to get the transform from the handle
		COGTransform* targetTransform = mTarget.Get()->FindComponent<COGTransform>();

		if (targetTransform != nullptr)
		{
			// Calculate the direction
			dir = (targetTransform->GetPosition() - origin).Normalized();
		}

		// Spawn the bullet with a random velocity
		GameObjectFactory::Instance()->InstantiateBullet(origin, dir, Random::Instance()->NextFloat(400.0f, 500.0f), "Enemy", "Player");

		// Reset the timers
		mTimeBetweenSpawns = Random::Instance()->NextFloat(0.7f, 1.5f);
		mTimeForNextSpawn = 0.0f;
	}
}

void COGEnemySpawner::SetTarget(const GameObjectHandle& pTarget)
{
	mTarget = pTarget;
}
