#include <iostream>
#include <SDL.h>
#include <glm\glm.hpp>
#include <GL\glew.h>
#include "Graphics.h"


// TODO: make an input class to handle user input and interraction, i.e. key presses, mouse tracking
//PROTOTYPES
int StartTimer(bool running);

int main(int argc, char *argv[])
{
	Graphics graphics(1000, 800);

	while (graphics.GetWindowState()) 
	{
		//TODO: Create a clear function to handle everything to do with clearing. 
		glClearColor(0.2f, 0.2f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		graphics.Update(); // Shows the user the environment so that they can interract with it. 
	}

	return 0;
}

/// Counts up in seconds in a given time interval.
int StartTimer(bool running)
{
	int secondCount{ 0 }, currentTime, lastTime;

	lastTime = SDL_GetTicks();

	while (running)
	{
		currentTime = SDL_GetTicks();

		if (currentTime - 1000 >= lastTime)
		{
			lastTime = SDL_GetTicks();
			secondCount++;
			std::cout << secondCount << std::endl;
		}
	}

	return secondCount;
}
