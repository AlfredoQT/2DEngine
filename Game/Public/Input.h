#pragma once

#include "Singleton.h"
#include "Engine\Public\Core\Types\Vector2.h"

enum class MouseButton
{
	LEFT = 0,
	MIDDLE,
	RIGHT
};

// Used to change states in input manager
enum class MouseButtonBitwise
{
	LEFT = 1 << static_cast<int>(MouseButton::LEFT),
	MIDDLE = 1 << static_cast<int>(MouseButton::MIDDLE),
	RIGHT = 1 << static_cast<int>(MouseButton::RIGHT),
};

// For the keeeyyys, just three for the moment
enum class KeyCode
{
	Alpha1 = 0,
	Alpha2,
	Alpha3,
	W,
	S,
	UpArrow,
	DownArrow
};

enum class KeyCodeBitwise
{
	Alpha1 = 1 << static_cast<int>(KeyCode::Alpha1),
	Alpha2 = 1 << static_cast<int>(KeyCode::Alpha2),
	Alpha3 = 1 << static_cast<int>(KeyCode::Alpha3),
	W = 1 << static_cast<int>(KeyCode::W),
	S = 1 << static_cast<int>(KeyCode::S),
	UpArrow = 1 << static_cast<int>(KeyCode::UpArrow),
	DownArrow = 1 << static_cast<int>(KeyCode::DownArrow)
};

class Input : public Singleton<Input>
{
public:

	// Input manager can access private members
	friend class InputManager;

	Input();
	~Input();

	Vector2 GetMousePosition() const;

	// Checks if the mouse button is currently being held down
	bool IsMouseButtonDown(MouseButton mouseButton) const;

	// Check if mouse is just pressed in that frame
	bool IsMouseButtonPressed(MouseButton mouseButton) const;

	// Check if mouse button was just released
	bool IsMouseButtonReleased(MouseButton mouseButton) const;

	bool IsKeyDown(KeyCode key);

	bool IsKeyPressed(KeyCode key);

	bool IsKeyReleased(KeyCode key);

private:

	// Hold mouse states
	int mMouseStates;

	// Holds key states
	int mKeyStates;

	// Hold prev mouse states, which will be set after everything is ran so that they are outdated
	int mPrevMouseStates;

	// Holds prev key states
	int mPrevKeyStates;

	Vector2 mMousePosition;
};
