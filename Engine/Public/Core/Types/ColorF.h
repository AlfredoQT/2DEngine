#pragma once

// Represents a colo

#include <cstdint>

typedef float GLclampf;

struct ColorF
{
	// Channels
	GLclampf R;
	GLclampf G;
	GLclampf B;
	GLclampf A;

	// Black color
	ColorF()
		: R(0)
		, G(0)
		, B(0)
		, A(255)
	{
	}

	ColorF(GLclampf pR, GLclampf pG, GLclampf pB)
		: R(pR)
		, G(pG)
		, B(pB)
		, A(255)
	{
	}

	ColorF(GLclampf pR, GLclampf pG, GLclampf pB, GLclampf pA)
		: R(pR)
		, G(pG)
		, B(pB)
		, A(pA)
	{
	}

	GLclampf* ToPtr()
	{
		return &R;
	}

};
