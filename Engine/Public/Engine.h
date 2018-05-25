#pragma once

struct SDL_Window;
struct SDL_Renderer;

// Defines the entry point for the engine
class Engine
{
public:

	int Init(const char* pTitle, const int& pWidth, const int& pHeight);

	// Run
	void Run();

	void Quit() const;

private:

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	float mWindowWidth;
	float mWindowHeight;

};