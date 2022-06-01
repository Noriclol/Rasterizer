#pragma once
#include "Vector3.h"
#include "S_Color.h"

struct LightNode {
	float ambientStrength;
	Color4 color;
	Vector3 position;

	LightNode() : ambientStrength(0.1f), color(1.0f, 1.0f, 1.0f, 1.0f){};
};