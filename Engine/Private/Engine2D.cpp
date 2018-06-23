#include "..\Public\Engine2D.h"
#include "SDL.h"
#include "Engine\Public\Core\Time.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "sdl2_gfxprimitives.h"
#include "Game\Public\IGame.h"
#include "SDL_ttf.h"

int Engine2D::Init(IGame* pGame, const char* pTitle, const int& pWidth, const int& pHeight)
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
		return 1;
	}

	// Initialize the font engine, and check for errors
	if (TTF_Init() != 0)
	{
		// Cleanup
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		return 1;
	}

	// Initialize the game
	pGame->Init(this);

	// No errors
	return 0;
}

void Engine2D::Run(IGame* pGame)
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

		// Run the game
		pGame->Run();

		SDL_RenderPresent(mRenderer);
	}
}

void Engine2D::Quit(IGame* pGame) const
{
	pGame->End();

	// Cleanup
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	TTF_Quit();

	// Simply quit all subsystems in sdl
	SDL_Quit();
}

// TODO: Move this somewhere else
void Engine2D::DrawLine(const Vector2 & pOrigin, const Vector2 & pTarget, const Color & pColor, const int& pOrderInLayer)
{
	SDL_SetRenderDrawColor(mRenderer, pColor.R, pColor.G, pColor.B, pColor.A);
	SDL_RenderDrawLine(mRenderer, static_cast<int>(pOrigin.x), static_cast<int>(pOrigin.y), static_cast<int>(pTarget.x), static_cast<int>(pTarget.y));
}

void Engine2D::DrawFillCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor, const int& pOrderInLayer)
{
	SDL_SetRenderDrawColor(mRenderer, pColor.R, pColor.G, pColor.B, pColor.A);

	// TODO: Replace this with mid point algorithm

	// I don't want to use tha anti aliased version because of performance
	filledCircleRGBA(mRenderer, static_cast<uint16_t>(pPosition.x), static_cast<uint16_t>(pPosition.y), static_cast<uint16_t>(pRadius), pColor.R, pColor.G, pColor.B, pColor.A);

}

void Engine2D::DrawCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor, const int& pOrderInLayer)
{
	SDL_SetRenderDrawColor(mRenderer, pColor.R, pColor.G, pColor.B, pColor.A);

	// TODO: Replace this with mid point algorithm

	// I don't want to use tha anti aliased version because of performance
	circleRGBA(mRenderer, static_cast<uint16_t>(pPosition.x), static_cast<uint16_t>(pPosition.y), static_cast<uint16_t>(pRadius), pColor.R, pColor.G, pColor.B, pColor.A);

}

void Engine2D::DrawRect(const Vector2 & pTopLeft, const Vector2 & pBotRight, const Color & pColor, const int& pOrderInLayer)
{
	SDL_SetRenderDrawColor(mRenderer, pColor.R, pColor.G, pColor.B, pColor.A);
	SDL_Rect rect;
	rect.x = static_cast<int>(pTopLeft.x);
	rect.y = static_cast<int>(pTopLeft.y);
	rect.w = static_cast<int>(pBotRight.x - pBotRight.x);
	rect.h = static_cast<int>(pBotRight.y - pBotRight.y);

	SDL_RenderDrawRect(mRenderer, &rect);
}

void Engine2D::DrawText(std::string pFontFile, const int& pFontSize, const std::string pMessage, const Vector2 & pPosition, const Color & pColor, const int& pOrderInLayer)
{
	// Go look for the font, I know it's slow, but SDL_ttf did not let me set the fontsize
	TTF_Font* font = TTF_OpenFont(pFontFile.c_str(), pFontSize);
	// Just return if we could not open the font
	if (font == nullptr)
	{
		return;
	}

	// Construct the color
	SDL_Color color;
	color.r = pColor.R;
	color.g = pColor.G;
	color.b = pColor.B;
	color.a = pColor.A;

	// Get a surface from sdl_ttf that will help create the texture, which will be rendered with the mRenderer
	// I use blended to be able to use the alpha channel
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, pMessage.c_str(), color);

	// Close the font on fail
	if (textSurface == nullptr)
	{
		TTF_CloseFont(font);
		return;
	}

	// Create the texture from the text surface
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);

	// A problem loading the texture
	if (textTexture == nullptr)
	{
		// Cleanup
		SDL_FreeSurface(textSurface);
		TTF_CloseFont(font);
		return;
	}

	// The rectangle to hold the texture
	SDL_Rect textRect;

	// Store the position in the screen in the rectangle
	textRect.x = static_cast<int>(pPosition.x);
	textRect.y = static_cast<int>(pPosition.y);

	// Query the texture, why did they made it this way. I guess I should write my extension at some point
	// Just query to assign the width and height of the rectangle
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);

	// Draw it, FINALLY
	SDL_RenderCopy(mRenderer, textTexture, nullptr, &textRect);

	// Clean up the texture and surface
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);

	// Close the font, pretty slow again
	TTF_CloseFont(font);
}
