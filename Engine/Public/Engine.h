#pragma once

#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct Color;
struct Vector2;
class IGame;

// Defines the entry point for the engine
class Engine
{
public:

	virtual int Init(IGame* pGame, const char* pTitle, const int& pWidth, const int& pHeight) = 0;

	// Run
	virtual void Run(IGame* pGame) = 0;

	virtual void Quit(IGame* pGame) const = 0;

	// TODO: Provide functionality for order in layer
	virtual void DrawLine(const Vector2& pOrigin, const Vector2& pTarget, const Color& pColor, const int& pOrderInLayer) = 0;
	virtual void DrawFillCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor, const int& pOrderInLayer) = 0;
	virtual void DrawCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor, const int& pOrderInLayer) = 0;
	virtual void DrawRect(const Vector2& pTopLeft, const Vector2& pBotRight, const Color& pColor, const int& pOrderInLayer) = 0;

	// This will open and close the font everytime, so it may be a little slow, but I can set different sizes every time
	// Drawn on top left
	virtual void DrawText(std::string pFontFile, const int& pFontSize, const std::string pMessage, const Vector2& pPosition, const Color& pColor, const int& pOrderInLayer) = 0;

protected:

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	int mWindowWidth;
	int mWindowHeight;

};