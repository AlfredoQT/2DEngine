#pragma once

#include "Singleton.h"
#include <random>

// Generates random numbers
class Random : public Singleton<Random>
{
public:

	// Returns a random float between 0 and 1
	float NextFloat();

	// Returns a random float between the given range
	float NextFloat(float pMin, float pMax);

	// Returns a random int between the given range
	int NextInt(int pMin, int pMax);

private:
	
	//Will be used to obtain a seed for the random number engine
	std::random_device mRD;

};
