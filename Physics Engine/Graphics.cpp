#include "Graphics.h"

///On creation of a graphics object, initializes SDL and creates a window.
Graphics::Graphics()
{
	//INITIALIZE SDL. 
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) // 0 is passed when we don't want to use any flags 
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	else 
		SDL_Log("SDL initialized!");
	
	//CREATE window flags
	Uint32 flags = SDL_WINDOW_OPENGL;

	//CREATE Window and Renderer
	SDL_CreateWindowAndRenderer(800, 600, flags, &win, &ren);
	SDL_SetWindowTitle(win, "Alex's Engine v0.1");
}


Graphics::~Graphics()
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}


void Graphics::Render() 
{

}

void Graphics::Update() 
{

}