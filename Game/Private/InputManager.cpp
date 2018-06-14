#include "Game\Public\InputManager.h"
#include "Game\Public\Input.h"
#include "Engine\Public\Core\Types\Vector2.h"

// Set singleton
InputManager* Singleton<InputManager>::mSingleton = nullptr;

InputManager::InputManager()
{
	mInput = Input::Instance();
}

InputManager::~InputManager()
{
	Input::DestroyInstance();
}

void InputManager::Update()
{
	// Reset states
	mInput->mMouseStates = 0;
	mInput->mKeyStates = 0;

	FetchMousePosition();

	// Get the states of the mouse now, before setting the previous ones
	// The previous ones have to be set after everything is run, so that there's a delay between the present state and the previous one
	// For example, when checking if a mouse button is just pressed, we just check if the mouse button is currently down and it was not previously pressed
	// This is possible because the previous ones were set just after the present ones are set
	// When we check for mouse released, we check first if the mouse button is no longer being held down and then if the prevDown is still happening
	// This is possible because the prev state still holds the previous state while the present one has already been updated
	FetchMouseNow();
	FetchKeysNow();
}

void InputManager::LateUpdate()
{
	// This will ensure that the previous mouse state is set after the mouse current state has been set, which means it will hold the
	// previous state of the mouse until late update gets called again. While the mouse current is being updated, this will not be updated
	// until the next frame
	mInput->mPrevMouseStates = mInput->mMouseStates;

	mInput->mPrevKeyStates = mInput->mKeyStates;
}

void InputManager::FetchMousePosition()
{
	//Get mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);

	// Set mouse position
	mInput->mMousePosition = Vector2(static_cast<float>(x), static_cast<float>(y));
}

// I'm not sure how to do this without repeating a lot of code, please comment on this one James
void InputManager::FetchMouseNow()
{
	//Get mouse state
	int x, y;
	Uint32 mouseState = SDL_GetMouseState(&x, &y);

	// Set mouse left
	if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		mInput->mMouseStates |= static_cast<int>(MouseButtonBitwise::LEFT);
	}
	// Set mouse middle
	if (mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE))
	{
		mInput->mMouseStates |= static_cast<int>(MouseButtonBitwise::MIDDLE);
	}
	// Set mouse right
	if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		mInput->mMouseStates |= static_cast<int>(MouseButtonBitwise::RIGHT);
	}
}

void InputManager::FetchKeysNow()
{
	// Get the key states from SDL
	int keys = 0;
	const Uint8* keyboardState = SDL_GetKeyboardState(&keys);

	// Check for key, comment on how to do this without much writing
	if (keyboardState[SDL_SCANCODE_1])
	{
		// Turn on the bit that handles the state for the alphanumeric 1
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::Alpha1);
	}
	if (keyboardState[SDL_SCANCODE_2])
	{
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::Alpha2);
	}
	if (keyboardState[SDL_SCANCODE_3])
	{
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::Alpha3);
	}
	if (keyboardState[SDL_SCANCODE_W])
	{
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::W);
	}
	if (keyboardState[SDL_SCANCODE_S])
	{
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::S);
	}
	if (keyboardState[SDL_SCANCODE_UP])
	{
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::UpArrow);
	}
	if (keyboardState[SDL_SCANCODE_DOWN])
	{
		mInput->mKeyStates |= static_cast<int>(KeyCodeBitwise::DownArrow);
	}
}

