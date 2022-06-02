#version 430

layout(location=0) out vec4 Color;

layout(location=2) in vec2 UVs;

layout(location=0) uniform sampler2D myTexture;

void main()
{

	Color = texture(myTexture, UVs);
}
