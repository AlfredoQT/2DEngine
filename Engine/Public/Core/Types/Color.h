// Represents a colo

#include <cstdint>

struct Color
{
	// Channels
	uint8_t R;
	uint8_t G;
	uint8_t B;
	uint8_t A;

	// Black color
	Color()
		: R(0)
		, G(0)
		, B(0)
		, A(255)
	{
	}

	Color(uint8_t pR, uint8_t pG, uint8_t pB)
		: R(pR)
		, G(pG)
		, B(pB)
		, A(255)
	{
	}

	Color(uint8_t pR, uint8_t pG, uint8_t pB, uint8_t pA)
		: R(pR)
		, G(pG)
		, B(pB)
		, A(pA)
	{
	}

};
