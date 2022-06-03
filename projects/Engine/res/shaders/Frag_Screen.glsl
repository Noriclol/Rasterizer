#version 430 core

in vec2 TextureCoords;

out vec4 ResultColor;

uniform sampler2D screenTexture;

void main()
{
    ResultColor = texture(screenTexture, TextureCoords);
}
