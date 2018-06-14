#pragma once

#include "Component.h"
#include "Engine\Public\Core\Types\Color.h"

class COGTransform;
class GameObject;

// A simple abstract class to represent shapes
class COGShape : public Component
{
public:

	COGShape(GameObject* pGO);

	static std::vector<COGShape*> shapeComponents;

	virtual void Initialize() override;
	virtual void Destroy() override;

	virtual void Render() = 0;

	void SetColor(const Color& pColor);

protected:

	Color mColor;
	COGTransform* mTransform;

};
