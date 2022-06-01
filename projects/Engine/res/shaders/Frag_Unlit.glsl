#version 430

layout(location=0) out vec4 Color;

layout(location=0) in vec4 color;
layout(location=1) in vec2 UVs;

layout(location=0) uniform sampler2D myTexture;

void main()
{

	Color = texture(myTexture, UVs);
}