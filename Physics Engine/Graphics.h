#pragma once
#include <SDL.h>
#include "Shader.h"

///Handles drawing and modifying how everything looks. 
class Graphics
{
public:

	Graphics(int w, int h);
	~Graphics();
	
	//Core Functions 
	void Update();
	void Render();
	
	//Returns False, if the window is closed and True, if the window is opened. 
	bool GetWindowState();

	//RENDER Algorithms
	//TODO: Raytacing

private: 
	
	//SDL objects
	SDL_Window * win; 
	SDL_Renderer * ren;
	SDL_GLContext glContext; // ------------------- Should this be a pointer??

	//Other Objects
	Shader shaderManager; 

	// -------------------------- TO ADD ------------------------------//
	//OpenGL vars

	/*
	*	Defining integer constants to improve readability. Any integers
	*	found in the code should be counting numbers, not ids.
	*/
	const int NULLID{ 0 };

	bool windowClosed;
};

