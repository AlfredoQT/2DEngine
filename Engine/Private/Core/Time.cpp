#include "..\..\Public\Core\Time.h"
#include "SDL.h"

// Get the ticks elapsed since the PC started
uint64_t Time::elapsedTicksPrevious = SDL_GetPerformanceCounter();

uint64_t Time::elapsedTicksNow = 0;

void Time::Update()
{
	// Get the elapsed ticks in the current frame
	elapsedTicksNow = SDL_GetPerformanceCounter();

	// Compute the difference between the elapsed ticks in the last and current frame
	float deltaElapsedTicks = elapsedTicksNow - elapsedTicksPrevious;

	// Performance frequency returns the number of ticks per second, so dividing the difference of ticks between frames over this value, I get the fraction of second between each frame
	float deltaTime = deltaElapsedTicks / static_cast<float>(SDL_GetPerformanceFrequency());

	// Updated the previous ticks, the now ticks will be ahead of it since they will get updated in the next frame just before the previous
	elapsedTicksPrevious = SDL_GetPerformanceCounter();
}
