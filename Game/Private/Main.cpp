#include "SDL.h"
#include "Engine\Public\EngineGL.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"
#include "Game\Public\TurretGame.h"

int main(int argc, char* args[])
{
	Engine* engine = new EngineGL();

	TurretGame game;

	if (engine->Init(&game, "AlfiEngine", 800, 600) != 0)
	{
		// SDL failed to initialize
		return 1;
	}
	
	engine->Run(&game);

	engine->Quit(&game);

	delete engine;

	return 0;
}
