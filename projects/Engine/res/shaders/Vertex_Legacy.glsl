#version 430
layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uv;


layout(location=1) out vec3 Normal;
layout(location=2) out vec2 UV;

uniform mat4 mvp;


void main()
{
	gl_Position =  mvp * vec4(pos, 1);
	Color = color;
	UVs = uv;
}
