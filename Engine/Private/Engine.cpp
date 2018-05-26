#include "..\Public\Engine.h"
#include "SDL.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Time.h"

int Engine::Init(const char* pTitle, const int& pWidth, const int& pHeight)
{
	// Initialize video and audio subsystems
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		// Some error
		return 1;
	}

	mWindow = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pWidth, pHeight, SDL_WINDOW_SHOWN);

	mWindowWidth = pWidth;
	mWindowHeight = pHeight;

	// Window was not successfully created
	if (mWindow == nullptr)
	{
		SDL_Quit();
		return 1;
	}

	// -1 initializes the first rendering driver that supports the flags
	// Renderer uses hardware acceleration
	// Present is synchronized with the refresh rate
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Renderer not successfully created
	if (mRenderer == nullptr)
	{
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	// No errors
	return 0;
}

void Engine::Run()
{
	// Loop until the user quits
	while (true)
	{
		// Union that contains structs for different event types
		SDL_Event e;
		// It dequeues events
		// Pass the address of e, so that the contents of the pointer can be modified, hence modifying e
		// In C++ you would use aliases &
		// Returns 1 if there was an event
		if (SDL_PollEvent(&e) != 0)
		{
			// Check if the user pressed the quit button
			// The program will not quit if we do not tell it to quit
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}

		// Determines the delta time, for now 
		Time::Update();
	}
}

void Engine::Quit() const
{
	// Cleanup
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);

	// Simply quit all subsystems in sdl
	SDL_Quit();
}
