#include "Game.h"

int main(int argc, char** argv)
{
	/*
	//Screen dimension constants
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

	// Window pointer
	SDL_Window* window = nullptr;

	// initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Create window
	window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// wait two seconds
	SDL_Delay(2000);

	// Destroy window
	SDL_DestroyWindow(window);

	// Quit SDL
	SDL_Quit();

	return 0;
	*/

	bool isGameInit = Game::instance().initialize();
	if (isGameInit) 
	{
		Game::instance().load();
		Game::instance().loop();
		Game::instance().unload();
	}
	Game::instance().close();
	return 0;
}