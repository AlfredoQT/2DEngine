#pragma once

#include "Component.h"

class GameObject;

// Keeps track of a game objects health
class COGHealth : public Component
{
public:

	COGHealth(GameObject* pGO);

	void ReceiveDamage(const float& pDamage);

	void SetMaxHealth(const float& pHealth);

	float GetCurrentHealth() const;
	float GetMaxHealth() const;

private:

	float mCurrentHealth;
	float mMaxHealth;

};
