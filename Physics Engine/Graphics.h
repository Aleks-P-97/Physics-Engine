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
	
	/*
	*	Encapsulate the vertex array and buffer objects into a data
	*   structure to make it easy to have many of them in the future.
	*/
	struct MeshGL
	{
		// VertexBufferObject for the normal
		GLuint normal_vbo{ 0 };

		// VertexBufferObject for the vertex positions
		GLuint position_vbo{ 0 };

		// VertexBufferObject for the texCoords
		GLuint texCoord_vbo{ 0 };

		// VertexBufferObject for the elements (indices)
		GLuint element_vbo{ 0 };

		// VertexArrayObject for the shape's vertex array settings
		GLuint vao{ 0 };

		// Needed for when we draw using the vertex arrays
		int element_count{ 0 };
	};

	//SDL objects
	SDL_Window * win; 
	SDL_Renderer * ren;
	SDL_GLContext glContext; // ------------------- Should this be a pointer??

	//Other Objects
	Shader shaderManager; 

	/*
	*	Defining integer constants to improve readability. Any integers
	*	found in the code should be counting numbers, not ids.
	*/
	const int NULLID{ 0 };

	bool windowClosed;
};

