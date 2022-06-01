#pragma once
#include <dinput.h>

#include "S_Color.h"

typedef unsigned char byte;
#define BYTE_TO_NORMALIZED 0.00390625f

struct Pixel
{
	byte r = 0;
	byte g = 0;
	byte b = 0;

	Color3 GetNormalized()
	{
		return Color3((float)r * BYTE_TO_NORMALIZED, (float)g * BYTE_TO_NORMALIZED, (float)b * BYTE_TO_NORMALIZED);
	}

	Pixel()= default;

	Pixel(float red, float green, float blue)
	{
		r = (byte)red;
		g = (byte)green;
		b = (byte)blue;
	}
};