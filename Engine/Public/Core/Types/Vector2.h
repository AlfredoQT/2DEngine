// Represents a two dimensional vector and operations on it

#pragma once

#include <cmath>

// I'm going to write my own engine, this is so much fun
struct Vector2
{
	float x;
	float y;

	Vector2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2(float pX, float pY)
	{
		x = pX;
		y = pY;
	}

	Vector2(const Vector2& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	float Size()
	{
		// Calculate magnitude
		return std::sqrt(x * x + y * y);
	}

	Vector2 Normalized()
	{
		Vector2 vector;

		// Get its length
		float magnitude = Size();

		// Avoid zero division error
		if (magnitude > 0.0f)
		{
			// Normalize it!
			vector.x = x / magnitude;
			vector.y = y / magnitude;
		}
		return vector;
	}

	// Addition
	Vector2 operator+(const Vector2& other)
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	// Allows vector subtraction
	Vector2 operator-(const Vector2& other)
	{
		return Vector2(this->x - other.x, this->y - other.y);
	}

	// I´ll be using this to calculate distances with the help of the subtraction operator
	// I took a lot of ideas from UE4 Github repo
	// I'll be using this in a lot of frames, that's why I decided not to use the Size method which uses sqrt
	float SizeSquared()
	{
		return x * x + y * y;
	}

	// Dot product
	float operator|(const Vector2& other)
	{
		return this->x * other.x + this->y * other.y;
	}

	// Scaling
	Vector2 operator*(const float& factor)
	{
		return Vector2(this->x * factor, this->y * factor);
	}

	// To use in OpenGL
	float* ToFloatPtr()
	{
		return &x;
	}

};
