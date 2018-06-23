#include "..\..\Public\COG\COGCircleShape.h"
#include "..\..\Public\World.h"
#include "..\..\Public\GameObject.h"
#include "Engine\Public\Engine.h"
#include "..\..\Public\COG\COGTransform.h"

COGCircleShape::COGCircleShape(GameObject * pGO)
	:COGShape(pGO)
{
}

void COGCircleShape::Render()
{
	// Draw a circle
	mGO->GetWorld()->GetEngine()->DrawCircle(mTransform->GetPosition(), mRadius, mColor, 0);
}

float COGCircleShape::GetRadius()
{
	return mRadius;
}

void COGCircleShape::SetRadius(const float & pRadius)
{
	mRadius = pRadius;
}
