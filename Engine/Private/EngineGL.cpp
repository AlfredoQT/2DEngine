#include "..\Public\EngineGL.h"
#include "GL\glew.h"
#include "SDL.h"

int EngineGL::Init(IGame * pGame, const char * pTitle, const int & pWidth, const int & pHeight)
{
	// Initialize video and audio subsystems
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		// Some error
		return 1;
	}

	// Initialize a window with the opengl flags
	mWindow = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pWidth, pHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS );

	mWindowWidth = pWidth;
	mWindowHeight = pHeight;

	// Window was not successfully created
	if (mWindow == nullptr)
	{
		SDL_Quit();
		return 1;
	}

	// Create the opengl context associated with the window
	mGLContext = SDL_GL_CreateContext(mWindow);

	// Apparently we have to do this, otherwise some of the glew functions will crash, also GL_TRUE is just a macro for 1, which means true
	glewExperimental = GL_TRUE;

	// Initialize the extension entry points. So this has to be callled after creating the context. It returns an error type
	GLenum error = glewInit();

	// Ignore the error
	glGetError();

	// Check if the error is OK
	if (error != GLEW_OK)
	{
		// Cleanup
		SDL_GL_DeleteContext(mGLContext);
		SDL_DestroyWindow(mWindow);

		// Simply quit all subsystems in sdl
		SDL_Quit();
		return 1;
	}

	// This makes our buffer swap synchronized with the monitor's vertical refresh
	// Double buffering
	if (SDL_GL_SetSwapInterval(1) != 0)
	{
		// Cleanup
		SDL_GL_DeleteContext(mGLContext);
		SDL_DestroyWindow(mWindow);

		// Simply quit all subsystems in sdl
		SDL_Quit();
		return 1;
	}

	return 0;
}

void EngineGL::Run(IGame * pGame)
{
}

void EngineGL::Quit(IGame * pGame) const
{
	// Cleanup
	SDL_GL_DeleteContext(mGLContext);
	SDL_DestroyWindow(mWindow);

	// Simply quit all subsystems in sdl
	SDL_Quit();
}

void EngineGL::DrawLine(const Vector2 & pOrigin, const Vector2 & pTarget, const Color & pColor)
{
}

void EngineGL::DrawFillCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor)
{
}

void EngineGL::DrawCircle(const Vector2 & pPosition, const float & pRadius, const Color & pColor)
{
}

void EngineGL::DrawRect(const Vector2 & pTopLeft, const Vector2 & pBotRight, const Color & pColor)
{
}

void EngineGL::DrawText(std::string pFontFile, const int & pFontSize, const std::string pMessage, const Vector2 & pPosition, const Color & pColor)
{
}
