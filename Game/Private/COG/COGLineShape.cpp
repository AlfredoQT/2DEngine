#include "..\..\Public\COG\COGLineShape.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Engine\Public\Engine.h"

COGLineShape::COGLineShape(GameObject * pGO)
	: COGShape(pGO)
{
}

void COGLineShape::Render()
{
	// Draw every line
	for (std::size_t i = 0; i < mPoints.size() - 1; ++i)
	{
		mGO->GetWorld()->GetEngine()->DrawLine(mPoints[i], mPoints[i + 1], mColor);
	}
}

void COGLineShape::AddPoint(const Vector2 & pPoint)
{
	// Add a point to the line shape
	mPoints.push_back(pPoint);
}

void COGLineShape::SetPoint(int pIndex, const Vector2 & pPoint)
{
	// Check boundaries
	if (pIndex < 0 || pIndex >= mPoints.size())
	{
		return;
	}
	// Set the new point
	mPoints[pIndex] = pPoint;
}
