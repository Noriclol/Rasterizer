#pragma once

enum ShaderType
{
	SType_none,
	SType_Vertex,
	SType_Fragment/*,
	Geometry*/
};


/**
 * \ A Data structure used to store a Shader.
 */
struct Shader
{
	ShaderType type;
	const char* s;

};