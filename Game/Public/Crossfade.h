#pragma once

// A helper to interpolate functions
namespace Crossfade
{
	// A parabola function
	float Arch2(float pTime);

	// Makes a crossfade between two functions that receive floats as parameters
	// 0% weight blend -> function one, 100% weight blend -> function two, 50% weight blend -> linear
	float Mix(float (*pFunctionOne)(float), float(*pFunctionTwo)(float), float pWeightBlend);
}
