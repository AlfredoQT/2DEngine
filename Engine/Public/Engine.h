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

	int Init(IGame* pGame, const char* pTitle, const int& pWidth, const int& pHeight);

	// Run
	void Run(IGame* pGame);

	void Quit(IGame* pGame) const;

	// TODO: Provide functionality for order in layer
	void DrawLine(const Vector2& pOrigin, const Vector2& pTarget, const Color& pColor);
	void DrawFillCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor);
	void DrawCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor);
	void DrawRect(const Vector2& pTopLeft, const Vector2& pBotRight, const Color& pColor);

	// This will open and close the font everytime, so it may be a little slow, but I can set different sizes every time
	// Drawn on top left
	void DrawText(std::string pFontFile, const int& pFontSize, const std::string pMessage, const Vector2& pPosition, const Color& pColor);

private:

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	int mWindowWidth;
	int mWindowHeight;



};