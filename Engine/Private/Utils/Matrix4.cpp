#include "..\..\Public\Utils\Matrix4.h"
#include "Engine\Public\Core\Types\Vector2.h"

float* Matrix4::ToFloatPtr()
{
	return &m11;
}

const float * Matrix4::ToFloatPtr() const
{
	return &m11;
}

void Matrix4::MakeTranslationMatrix(Matrix4* pOut, const Vector2 & pTranslation)
{
	//// The translation matrix

	//// The identity bit
	//pMatrixOut->m11 = pMatrixOut->m22 = pMatrixOut->m33 = pMatrixOut->m44 = 1.0f;

	//// Hold the info of the translation
	//pMatrixOut->m14 = pTranslation.x;
	//pMatrixOut->m24 = pTranslation.y;
	//pMatrixOut->m34 = 0.0f; // We don't really care about z axis for now

	//// The other part of the identity matrix, and that's it, I've got a translation matrix
	//pMatrixOut->m12 = pMatrixOut->m13 = pMatrixOut->m21 = pMatrixOut->m23 = pMatrixOut->m31 = pMatrixOut->m32 = pMatrixOut->m41 = pMatrixOut->m42 = pMatrixOut->m43 = 0.0f;

	pOut->m11 = 1.0f;
	pOut->m22 = 1.0f;
	pOut->m33 = 1.0f;
	pOut->m44 = 1.0f;

	pOut->m12 = pOut->m13 = pOut->m14 = 0.0f;
	pOut->m21 = pOut->m23 = pOut->m24 = 0.0f;
	pOut->m31 = pOut->m32 = pOut->m34 = 0.0f;

	pOut->m41 = pTranslation.x;	// identity matrix apart from this translation
	pOut->m42 = pTranslation.y;
	pOut->m43 = 0.0f;
}

void Matrix4::OrthographicProjectionMatrix(Matrix4* pOut, float fWidth, float fHeight, float fNearPlane, float fFarPlane)
{
	// http://msdn.microsoft.com/en-us/library/windows/desktop/dd373965%28v=vs.85%29.aspx
	// http://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/orthographic-projection-matrix
	// https://blog.demofox.org/2017/03/31/orthogonal-projection-matrix-plainly-explained/

	pOut->m11 = 2.0f / fWidth;
	pOut->m12 = 0.0f;
	pOut->m13 = 0.0f;
	pOut->m14 = 0.0f;

	pOut->m21 = 0.0f;
	pOut->m22 = 2.0f / -fHeight;
	pOut->m23 = 0.0f;
	pOut->m24 = 0.0f;

	pOut->m31 = 0.0f;
	pOut->m32 = 0.0f;
	pOut->m33 = -2.0f / (fFarPlane - fNearPlane);
	pOut->m34 = 0.0f;

	pOut->m41 = -1.0f;
	pOut->m42 = 1.0f;
	pOut->m43 = -((fFarPlane + fNearPlane) / (fFarPlane - fNearPlane));
	pOut->m44 = 1.0f;
}
