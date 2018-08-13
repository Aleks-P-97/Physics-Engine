#include "Graphics.h"
#include <GL\glew.h> 

///On creation of a graphics object, initializes SDL and creates a window.
Graphics::Graphics(int w, int h)
{
	//INITIALIZE SDL. 
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) // 0 is passed when we don't want to use any flags 
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	else 
		SDL_Log("SDL initialized!");
	
	//SET attributes
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);  //Number of bits used to display red/ Nuber of shades of red that can be displayed
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8); 
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //The data in bits allocated per pixel, 32 bits of colour data -> 2 to the power of 8
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //Creates one buffer but allocates space for two

	//CREATE window flags
	Uint32 flags = SDL_WINDOW_OPENGL;

	//CREATE Window and Renderer
	SDL_CreateWindowAndRenderer(w, h, flags, &win, &ren);
	SDL_SetWindowTitle(win, "Alex's Physics Engine v0.1");

	//CREATE Context (allows the GPU to draw on the SDL Window)
	glContext = SDL_GL_CreateContext(win);

	//INITIALIZE GLEW
	GLenum status = glewInit();

	//Check if initialized correctly
	if (status != GLEW_OK)
	{
		SDL_Log("Unable to initialize GLEW");
	}

	windowClosed = false;
}


Graphics::~Graphics()
{
	SDL_DestroyRenderer(ren);
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(win);
	SDL_Quit();
}


void Graphics::Update() 
{
	//Swaps the buffers
	SDL_GL_SwapWindow(win);

	//HANDLE OpenGL Events 
	SDL_Event e; 

	while (SDL_PollEvent(&e))
	{
		//TODO: Convert to switch 
		if (e.type == SDL_QUIT) 
		{
			windowClosed = true; 
		}
	}
}


void Graphics::Render() 
{
	
}


bool Graphics::GetWindowState()
{
	return !windowClosed; // --------------- Would this be confusing later on ??
}