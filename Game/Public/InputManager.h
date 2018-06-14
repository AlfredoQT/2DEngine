#pragma once

#include "Singleton.h"
#include "SDL.h"

class InputManager : public Singleton<InputManager>
{
public:

	InputManager();
	~InputManager();

	// Updates the inputs
	void Update();

	// After everythin is ran
	void LateUpdate();

private:

	class Input * mInput;

	// Fetch all mouse states
	void FetchMousePosition();

	// Fetch mouse states in the present
	void FetchMouseNow();

	void FetchKeysNow();

};
