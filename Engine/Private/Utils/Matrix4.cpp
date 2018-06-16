#include "..\..\Public\Utils\Matrix4.h"
#include "Engine\Public\Core\Types\Vector2.h"

float* Matrix4::ToFloatPtr()
{
	return &m11;
}

void Matrix4::MakeTranslationMatrix(Matrix4* pMatrixOut, const Vector2 & pTranslation)
{
	// The translation matrix

	// The identity bit
	pMatrixOut->m11 = pMatrixOut->m22 = pMatrixOut->m33 = pMatrixOut->m44 = 1.0f;

	// Hold the info of the translation
	pMatrixOut->m14 = pTranslation.x;
	pMatrixOut->m24 = pTranslation.y;
	pMatrixOut->m34 = 0.0f; // We don't really care about z axis for now

	// The other part of the identity matrix, and that's it, I've got a translation matrix
	pMatrixOut->m12 = pMatrixOut->m13 = pMatrixOut->m21 = pMatrixOut->m23 = pMatrixOut->m41 = pMatrixOut->m42 = pMatrixOut->m43 = 0.0f;
}
