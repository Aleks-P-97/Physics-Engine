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
		std::cout << "Error Detected in CreateShader()"; //TODO: check why this is triggered! 
		std::cerr << log << std::endl;
	}
	else
	{
		std::cout << "Shader: " << shader << " compiled sucessfully. " << std::endl;
	}
}


void Shader::Link() //TODO : Add a list of shader types and a list of paths so that all the shaders can be created in a for loop.
{
	//CREATES A VERTEX SHADER
	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, "./Shader files/shader.vs"); 

	//CREATES A FRAGMENT SHADER
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, "./Shader files/shader.fs"); 

	program = glCreateProgram();

	//Handle vertex shader
	glAttachShader(program, vertexShader);
	//glBindAttribLocation(program, eVertPos, "vertex_position");  //TODO
	//glBindAttribLocation(program, eVertNorm, "vertex_normal");  //TODO
	//glBindAttribLocation(program, eTexCoord, "texCoord"); //TODO
	glDeleteShader(vertexShader);
	glDetachShader(program, vertexShader); // TO Make sure it's in the right place

	//Handle fragment shader
	glAttachShader(program, fragmentShader);
	//glBindFragDataLocation(program, eFragColour, "fragment_colour");  //TODO
	glDeleteShader(fragmentShader);
	glDetachShader(program, fragmentShader); // TO Make sure it's in the right place
	glLinkProgram(program);

	CheckLink();
}


void Shader::CheckLink()
{
	GLint link_status = GL_FALSE;
	glGetProgramiv(program, GL_LINK_STATUS, &link_status);

	std::cout << "Link status: " << link_status << std::endl; 

	if (link_status != GL_TRUE)
	{
		const int string_length = 1024;
		GLchar errorLog[string_length] = "";
		glGetProgramInfoLog(program, string_length, NULL, errorLog);
		std::cout << "Error Detected in LinkProgram()"; //TODO: check why this is triggered!
		std::cerr << errorLog << std::endl;
	}
	else 
	{
		std::cout << "Successful Link Established!" << std::endl; 
	}
}
