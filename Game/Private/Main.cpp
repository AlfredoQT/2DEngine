#include "SDL.h"
#include "Engine\Public\Engine.h"

int main(int argc, char* args[])
{
	Engine engine;

	if (engine.Init("2DEngine", 800, 600) != 0)
	{
		// SDL failed to initialize
		return 1;
	}
	
	engine.Run();

	engine.Quit();

	return 0;
}
