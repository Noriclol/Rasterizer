#pragma once

#include <GL/glew.h>
#include <string>
#include <unordered_map>

#include "Vector3.h"
#include "Matrix4.h"
#include "S_Color.h"




class ShaderResource {
public:

	GLuint program;
	GLuint vertex;
	GLuint fragment;
	

	ShaderResource(std::string psPath, std::string vsPath);
	~ShaderResource();
	
	void Bind() const { glUseProgram(program); }
	static void Unbind() { glUseProgram(0); };

	//Uniforms

	//structs
	void SetValue(const std::string& name, const Matrix4& mat, const bool transpose = true)	{ glUniformMatrix4fv(GetLocation(name), 1, transpose, (GLfloat*)& mat); }
	void SetValue(const std::string& name, const Vector3& v)								{ glUniform3f(GetLocation(name), v[0], v[1], v[2]); }
	void SetValue(const std::string& name, const Color3& c)									{ glUniform3f(GetLocation(name), c.r, c.g, c.b); }
	void SetValue(const std::string& name, const Color4& c)									{ glUniform4f(GetLocation(name), c.r, c.g, c.b, c.a); }
	//Basic values
	void SetValue(const std::string& name, const int value)									{ glUniform1i(GetLocation(name), value); }
	void SetValue(const std::string& name, const float value)								{ glUniform1f(GetLocation(name), value); }
	void SetValue(const std::string& name, const bool value)								{ glUniform1i(GetLocation(name), value); }

	void SetUniformMatrix4fv(unsigned int location, Matrix4 mvp)
	{
		glUniformMatrix4fv(location, 1, true, (GLfloat*)&mvp);
	}


private:

	std::unordered_map<std::string, int> cache;

	std::string LoadShader(std::string path);

	void CheckCompileErrors(const unsigned int shader);

	void CheckLinkErrors() const;

	int GetLocation(const std::string& name);
};