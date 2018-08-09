#include <iostream>
#include <SDL.h>
#include <glm\glm.hpp>
#include "Graphics.h"

//PROTOTYPES
void HandleEvent(); // TODO: make an input class to handle user input and interraction, i.e. key presses, mouse tracking
int StartTimer(bool running);

int main(int argc, char *argv[])
{
	Graphics graphics;
	bool running = true;

	while (running) //Currently infinite loop!!!
	{
		graphics.Render(); // Shows the user the environment so that they can interract with it. 
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
