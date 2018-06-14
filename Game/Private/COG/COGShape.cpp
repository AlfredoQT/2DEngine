#include "..\..\Public\COG\COGShape.h"
#include "..\..\Public\COG\COGTransform.h"
#include "..\..\Public\GameObject.h"

std::vector<COGShape*> COGShape::shapeComponents;

COGShape::COGShape(GameObject * pGO)
	: Component(pGO)
{
}

void COGShape::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>();
	AddToComponentVector(shapeComponents);
}

void COGShape::Destroy()
{
	RemoveFromComponentVector(shapeComponents);
}

void COGShape::SetColor(const Color & pColor)
{
	mColor = pColor;
}
