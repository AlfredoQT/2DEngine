#include "..\Public\Random.h"

// Singleton
Random* Singleton<Random>::mSingleton = nullptr;

float Random::NextFloat()
{
	//Standard mersenne_twister_engine seeded with random device
	std::mt19937 gen(mRD());

	// Produces the random float
	std::uniform_real_distribution<float> dis(0.0f, 1.0f);

	return dis(gen);
}

float Random::NextFloat(float pMin, float pMax)
{
	//Standard mersenne_twister_engine seeded with random device
	std::mt19937 gen(mRD());

	// Produces the random float
	std::uniform_real_distribution<float> dis(pMin, pMax);

	return dis(gen);
}

int Random::NextInt(int pMin, int pMax)
{
	//Standard mersenne_twister_engine seeded with random device
	std::mt19937 gen(mRD());

	// Produces the random int
	std::uniform_int_distribution<int> dis(pMin, pMax);

	return dis(gen);
}
