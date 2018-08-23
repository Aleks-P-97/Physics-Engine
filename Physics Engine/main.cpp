#include <iostream>
#include <SDL.h>
#include <glm\glm.hpp>
#include <GL\glew.h>
#include "Graphics.h"


// TODO: Make an input class to handle user input and interraction, i.e. key presses, mouse tracking.
//PROTOTYPES
int StartTimer(bool running);

int main(int argc, char *argv[])
{
	Graphics graphics(1000, 800);

	while (graphics.GetWindowState()) 
	{
		graphics.Update(); 
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
