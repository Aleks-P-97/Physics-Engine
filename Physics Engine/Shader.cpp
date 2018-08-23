#include "Shader.h"


Shader::Shader()
{
}


Shader::~Shader()
{
}


GLuint Shader::CreateShader(GLenum shaderType, const std::string &path)
{
	GLuint shader = glCreateShader(shaderType);
	std::string shaderData = ReadShader(path);

	const char * shaderCode = shaderData.c_str();
	glShaderSource(shader, 1, (const GLchar **)&shaderCode, NULL);
	glCompileShader(shader);
	
	CheckShaderCompilation(shader);

	return shader;
}


std::string Shader::ReadShader(const std::string &path)
{
	std::string data;
	std::string line;

	std::ifstream shaderFile; 
	shaderFile.open((path).c_str());

	if (shaderFile.is_open())
	{
		//while there's more to read
		while (shaderFile.good()) 
		{
			getline(shaderFile, line);
			data.append(line + "\n");
		}
	}
	else 
	{
		std::cerr << "Unable to load the (" << path << ") shader file!" << std::endl; 
	}

	return data;
}


void Shader::CheckShaderCompilation(GLuint shader)
{
	GLint compile_status = GL_FALSE;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);

	if (compile_status != GL_TRUE)
	{
		const int string_length = 1024;
		GLchar log[string_length] = "";
		glGetShaderInfoLog(shader, string_length, NULL, log);
		std::cerr << log << std::endl;
	}
}


void Shader::LinkProgram()
{
	//CREATES A VERTEX SHADER
	GLuint vertex_shader = CreateShader(GL_VERTEX_SHADER, "resource:///vs.glsl");

	//CREATES A FRAGMENT SHADER
	GLuint fragment_shader = CreateShader(GL_FRAGMENT_SHADER, "resource:///fs.glsl");
}


void Shader::CheckLink(GLuint shader)
{

}
