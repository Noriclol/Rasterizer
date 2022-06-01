#include "Resource_Shader.h"

#include "Matrix4.h"
#include "Vector3.h"

#include <iostream>
#include <fstream>
#include <sstream>



ShaderResource::~ShaderResource() {
	glDeleteProgram(program);
}

ShaderResource::ShaderResource(std::string psPath, std::string vsPath)
{
	std::cout << "\n__Init Shader Resource_BEGIN_\n\n";


	if (strlen(psPath.c_str()) == 0 || strlen(vsPath.c_str()) == 0)
	{
		std::cout << "Error Initializing Shader, Check constuctor arguments\n";
		return;
	}
	std::cout << "Both Shaders found from sources\n";

	


	//Load and convert shaderData from sources
	std::string vss = LoadShader(vsPath);
	std::string fss = LoadShader(psPath);

	const char* vs = vss.c_str();
	const char* fs = fss.c_str();
	GLint length;


	//Create and Compile Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	length = static_cast<GLint>(std::strlen(vs));

	glShaderSource(vertex, 1, &vs, &length);
	glCompileShader(vertex);

	CheckCompileErrors(vertex);

	//Create and Compile Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	length = static_cast<GLint>(std::strlen(fs));

	glShaderSource(fragment, 1, &fs, &length);
	glCompileShader(fragment);

	CheckCompileErrors(fragment);



	//Create Program
	program = glCreateProgram();

	//Attach Shaders to program handle
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);
	glValidateProgram(program);
	CheckLinkErrors();


	//glDeleteShader(vertex);
	//glDeleteShader(fragment);


	std::cout << "\n__Init Shader Resource_COMPLETE_\n\n";

}

std::string ShaderResource::LoadShader(std::string path)
{
	std::fstream inFile;
	std::stringstream stream;
	std::string line;
	inFile.open(path, std::ios::in);
	while (std::getline(inFile, line)) {
		stream << line << std::endl;
	}
	inFile.close();
	return stream.str();
}

void ShaderResource::CheckCompileErrors(const unsigned int shader)
{
	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

		char* errorMsg = static_cast<char*>(_malloca(length * sizeof(char)));
		glGetShaderInfoLog(shader, length, &length, errorMsg);

		std::cout << "Failed to COMPILE the shader. Error: " << errorMsg << "\n";

		glDeleteShader(shader);
	}
	std::cout << "Shader w handle [" << std::to_string(shader) << "] Compiled Successfully\n";
}

void ShaderResource::CheckLinkErrors() const
{
	int result;
	glGetProgramiv(program, GL_LINK_STATUS, &result);

	if (!result)
	{
		int length;
		glGetProgramiv(program, GL_LINK_STATUS, &length);

		char* errorMsg = static_cast<char*>(_malloca(length * sizeof(char)));
		glGetProgramInfoLog(program, length, &length, errorMsg);

		std::cout << "Failed to LINK the shader. Error: " << errorMsg << "\n";

		glDeleteShader(program);
	}
	std::cout << "Shaders Linked to Program Successfully\n";
}

int ShaderResource::GetLocation(const std::string& name)
{
	// returns cached value, if found
	if (cache.find(name) != cache.end())
		return cache[name];

	// otherwise; insert the value for future look-up
	const int location = glGetUniformLocation(program, name.c_str());
	cache[name] = location;

	return location;
}

