#pragma once

#include <GL/glew.h>
#include <string>
#include <vector>

#include "Vector3.h"
#include "S_Color.h"

/// <summary>
/// Texture Resorce that can load textures from a file.
/// </summary>
class TextureResource {

public:

	unsigned int iTBufferHandle;
	unsigned char* textureBuffer;
	std::string filePath;
	int width;
	int height;
	int BPP;
	unsigned int slot;



	TextureResource(const std::string& path);
	~TextureResource();

	void Init(const std::string& path);

	void Bind(unsigned int slot = 0);
	void Unbind();

	Color3 Sample(const Vector3& uv) const;
	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
};
