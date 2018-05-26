#pragma once

#include <cstdint>

// Makes stuff with the time
class Time
{
private:

	// Stores the current elapsed ticks in the previous frame
	static uint64_t elapsedTicksPrevious;
	// Stores the current elapsed ticks in the current frame
	static uint64_t elapsedTicksNow;

public:

	// Fraction of a second elapsed beween frames
	static float deltaTime;

	// Updates delta time, for now
	static void Update();

};
