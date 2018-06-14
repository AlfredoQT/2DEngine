#include "..\..\Public\COG\COGHealth.h"
#include "Game\Public\FMath.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\GameObjectHandle.h"

COGHealth::COGHealth(GameObject * pGO)
	: Component(pGO)
	, mCurrentHealth(0.0f)
	, mMaxHealth(0.0f)
{
}

void COGHealth::ReceiveDamage(const float& pDamage)
{
	// Take the damage, clamp it for safe measure
	mCurrentHealth = FMath::Clamp(mCurrentHealth - pDamage, 0.0f, mMaxHealth);

	// Killed?
	if (mCurrentHealth <= 0.0f)
	{
		mGO->GetWorld()->Delete(mGO->GetHandle());
	}
}

void COGHealth::SetMaxHealth(const float& pHealth)
{
	mMaxHealth = pHealth;
	mCurrentHealth = pHealth;
}

float COGHealth::GetCurrentHealth() const
{
	return mCurrentHealth;
}

float COGHealth::GetMaxHealth() const
{
	return mMaxHealth;
}
