#pragma once

struct Vector2;

// A simple representation of a 4x4 matrix
class Matrix4
{
public:

	// A pointer to the first element of the matrix
	float* ToFloatPtr();

	// Make the translation matrix, its less memory this way
	static void MakeTranslationMatrix(Matrix4* pMatrixOut, const Vector2& pTranslation);

public:

	// ToPtr will return the pointer to the first element in the matrix. If you go through it with pointer arithmetic, you will get the others because
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;

};
