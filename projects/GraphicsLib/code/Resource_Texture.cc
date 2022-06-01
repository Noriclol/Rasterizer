#include "Resource_Texture.h"

#include "S_Pixel.h"


#ifndef STBI_INCLUDE_STB_IMAGE_H //headerguard
#include "stb_image.h"
#endif
//struct RGB;

TextureResource::TextureResource(const std::string& path):iTBufferHandle(0), textureBuffer{}, width(0), height(0), BPP(0), slot(0) { Init(path); }

TextureResource::~TextureResource()
{
	glDeleteTextures(1, &iTBufferHandle);
}

void TextureResource::Init(const std::string& path)
{
	stbi_set_flip_vertically_on_load(1);
	textureBuffer = stbi_load(path.c_str(), &width, &height, &BPP, 3);

	glGenTextures(1, &iTBufferHandle);

	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, iTBufferHandle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB, (GLsizei)width, (GLsizei)height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureBuffer);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, NULL);
	//Unbind();
	if (textureBuffer) {
		stbi_image_free(textureBuffer);
	}
}

void TextureResource::Bind(unsigned int slot)
{
	this->slot = slot;
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, iTBufferHandle);
}

void TextureResource::Unbind()
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, NULL);
}

Color3 TextureResource::Sample(const Vector3& uv) const
{
	float u = uv.x, v = uv.y;
	//Applies UV wrapping if UV out of bounds.
	if (u < 0.0f || u > 1.0f)
	{
		u = fmodf(u, 1.0f);
		if (u < 0.0f){
			u = 1.0f - u;
		}
	}
	if (v < 0.0f || v > 1.0f)
	{
		v = fmodf(v, 1.0f);
		if (v < 0.0f) {
			v = 1.0f - v;
		}
	}
	// to pixel values and round down.
	int x = u * (float)(width - 1), y = v * (float)(height - 1);

	Pixel* pixels = (Pixel*)textureBuffer;

	return pixels[(y * width + x)].GetNormalized();
}
