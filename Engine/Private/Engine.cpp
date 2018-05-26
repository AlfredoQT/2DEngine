#include "..\Public\Engine.h"
#include "SDL.h"
#include "Engine\Public\Utils\Debug.h"
#include "Engine\Public\Core\Time.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "sdl2_gfxprimitives.h"

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

		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);

		// Determines the delta time, for now 
		Time::Update();

		SDL_RenderPresent(mRenderer);
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

// TODO: Move this somewhere else
void Engine::DrawLine(const Vector2 & pOrigin, const Vector2 & pTarget, const Color & pColor)
{
	SDL_SetRenderDrawColor(mRenderer, pColor.R, pColor.G, pColor.B, pColor.A);
	SDL_RenderDrawLine(mRenderer, static_cast<int>(pOrigin.x), static_cast<int>(pOrigin.y), static_cast<int>(pTarget.x), static_cast<int>(pTarget.y));
}

void Engine::DrawFillCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor)
{
	SDL_SetRenderDrawColor(mRenderer, pColor.R, pColor.G, pColor.B, pColor.A);
	
	// TODO: Replace this with mid point algorithm

	// I don't want to use tha anti aliased version because of performance
	filledCircleRGBA(mRenderer, static_cast<uint16_t>(pPosition.x), static_cast<uint16_t>(pPosition.y), static_cast<uint16_t>(pRadius), pColor.R, pColor.G, pColor.B, pColor.A);

}
