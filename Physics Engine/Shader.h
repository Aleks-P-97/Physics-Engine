#pragma once

#include <iostream>
#include <fstream> 
#include <vector>
#include <map>
#include <string> 
#include <GL\glew.h>

///This class loads and builds shaders files. 
class Shader
{
public:

	Shader();
	~Shader();

	///Load a shader from a file, compiles it and checks if compiled correctly.
	GLuint CreateShader(GLenum shaderType, const std::string &path);
	
	/**
	*   Shaders are loaded from a text file into a string which is
	*	passed to OpenGL for compiling. Compile errors can be
	*	queried via the info log.
	*/
	std::string ReadShader(const std::string &path);
	
	/*
	*   Creates a program object to host the shaders and their
	*   settings. This program object attempts to bind the shaders
	*   together when it is linked. If the shaders aren't compatible
	*   the link process will fail. Once the program gets the shader 
	*   stage information, the shaders can be detatched and deleted. 
	*/
	void LinkProgram();

	
private: 
	GLuint program; 

	// The enums are used to keep track of the magic numbers in OpenGL.
	enum VertexAttribIndices
	{
		kVertPos = 0,
		kVertNorm = 1,
		kTexCoord = 2
	};

	/*
	*	Called in CreateShader(). Test if the shader compiled successfully. 
	*   If not then get the error log and display in the console window. 
	*/
	void CheckShaderCompilation(GLuint shader);

	/*
	*	Called in LinkProgram(). Test if the shader program linked successfully.
	*   If not then get the error log and display in the console window.
	*/
	void CheckLink(GLuint shader);
};

