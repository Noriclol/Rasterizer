#version 430



layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uv;

layout(location=0) out vec4 Color;

void main()
{
	Color.xy = uv;
	Color.z = 0;
}
