#pragma once

#include "COGShape.h"
#include "Engine\Public\Core\Types\Vector2.h"

class GameObject;

class COGLineShape: public COGShape
{
public:

	COGLineShape(GameObject* pGO);

	virtual void Render() override;

	void AddPoint(const Vector2& pPoint);

	void SetPoint(int pIndex, const Vector2& pPoint);

private:

	// Points across the line
	std::vector<Vector2> mPoints;

};
