#pragma once
#include <SDL.h>

///Handles drawing and modifying how everything looks. 
class Graphics
{
public:

	Graphics();
	~Graphics();

	void Render();
	void Update();

private: 
	SDL_Renderer * ren;
	SDL_Window * win; 
};

