#include "SDL.h"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		return 1;
	}
	SDL_Quit();

	return 0;
}
