#pragma once
#include "S_Color.h"


/**
 * \ A struct containing all required MaterialData
 */
struct Material {
	Color4 ambientColor = Color4(0.0f, 0.0f, 0.0f, 1.0f);
	Color4 diffuseColor = Color4(1.0f, 1.0f, 1.0f, 1.0f);
	Color4 specularColor = Color4(0.5f, 0.5f, 0.5f, 1.0f);
	float shininess = 1.0f;
	Material() = default;
	};
