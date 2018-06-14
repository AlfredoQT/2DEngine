#pragma once

#include "COGShape.h"

class GameObject;

class COGCircleShape : public COGShape
{
public:

	COGCircleShape(GameObject* pGO);

	virtual void Render() override;

	float GetRadius();
	void SetRadius(const float& pRadius);

private:

	float mRadius;

};
