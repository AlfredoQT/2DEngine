#pragma once

#include <math.h>

// A library of  methods for moi
namespace FMath
{
	const float PI = 3.141592f;
	const float Deg2Rad = PI / 180.0f;

	template<class T>
	T Max(const T a, const T b)
	{
		return a > b ? a : b;
	}

	template<class T>
	T Min(const T a, const T b)
	{
		return a < b ? a : b;
	}

	template<class T>
	T Clamp(const T value, const T min, const T max)
	{
		return Max(min, Min(value, max));
	}

	// I did not want to implement my own cosine function for this assignment
	template<class T>
	T Cos(const T angle)
	{
		return cos(angle);
	}

	// I did not want to implement my own sine function for this assignment
	template<class T>
	T Sin(const T angle)
	{
		return sin(angle);
	}

	template<class T>
	T Atan2(const T y, const T x)
	{
		return atan2(y, x);
	}

	template<class T>
	T Abs(const T x)
	{
		return x > 0 ? x : -x;
	}

};
