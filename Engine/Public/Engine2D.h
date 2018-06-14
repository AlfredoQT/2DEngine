#pragma once

#include "Engine.h"

struct SDL_Window;
struct SDL_Renderer;
struct Color;
struct Vector2;
class IGame;

// Defines the entry point for the engine
class Engine2D : public Engine
{
public:

	virtual int Init(IGame* pGame, const char* pTitle, const int& pWidth, const int& pHeight) override;

	// Run
	virtual void Run(IGame* pGame) override;

	virtual void Quit(IGame* pGame) const override;

	// TODO: Provide functionality for order in layer
	virtual void DrawLine(const Vector2& pOrigin, const Vector2& pTarget, const Color& pColor) override;
	virtual void DrawFillCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor) override;
	virtual void DrawCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor) override;
	virtual void DrawRect(const Vector2& pTopLeft, const Vector2& pBotRight, const Color& pColor) override;

	// This will open and close the font everytime, so it may be a little slow, but I can set different sizes every time
	// Drawn on top left
	virtual void DrawText(std::string pFontFile, const int& pFontSize, const std::string pMessage, const Vector2& pPosition, const Color& pColor) override;

};