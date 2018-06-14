#include "Game\Public\Input.h"

// Initialize the singleton
Input* Singleton<Input>::mSingleton = nullptr;

Input::Input()
	: mMouseStates(0)
	, mKeyStates(0)
	, mPrevMouseStates(0)
	, mPrevKeyStates(0)
{
}

Input::~Input()
{
}

Vector2 Input::GetMousePosition() const
{
	return mMousePosition;
}

bool Input::IsMouseButtonDown(MouseButton mouseButton) const
{
	// Check if the mouse state is down at that bit (set at input manager)
	return mMouseStates & 1 << static_cast<int>(mouseButton);
}

bool Input::IsMouseButtonPressed(MouseButton mouseButton) const
{
	// Mouse prev state has not yet been updated
	// When it gets updated after everything is ran, and mouse is still down, this will no longer be true
	return (mMouseStates & 1 << static_cast<int>(mouseButton)) && !(mPrevMouseStates & 1 << static_cast<int>(mouseButton));
}

bool Input::IsMouseButtonReleased(MouseButton mouseButton) const
{
	// Mouse prev state has not yet been updated
	// When it gets updated after everything is ran, and mouse has been released, this will no longer be true
	return !(mMouseStates & 1 << static_cast<int>(mouseButton)) && (mPrevMouseStates & 1 << static_cast<int>(mouseButton));
}

bool Input::IsKeyDown(KeyCode key)
{
	return mKeyStates &	1 << static_cast<int>(key);
}

bool Input::IsKeyPressed(KeyCode key)
{
	return (mKeyStates & 1 << static_cast<int>(key)) && !(mPrevKeyStates & 1 << static_cast<int>(key));
}

bool Input::IsKeyReleased(KeyCode key)
{
	return !(mKeyStates & 1 << static_cast<int>(key)) && (mPrevKeyStates & 1 << static_cast<int>(key));
}
