#pragma once
#include <algorithm>


struct Color4 {

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 1.0f;

	Color4() = default;

	Color4(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color4(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	Color4 operator +(const Color4& other) const
	{
		return Color4(	
						std::clamp(r + other.r, 0.0f, 1.0f),
						std::clamp(g + other.g, 0.0f, 1.0f), 
						std::clamp(b + other.b, 0.0f, 1.0f), 
						std::clamp(a + other.a, 0.0f, 1.0f));
	};

	Color4 operator *(float f) const
	{
		return Color4(	
						std::clamp(r * f, 0.0f, 1.0f),	
						std::clamp(g * f, 0.0f, 1.0f), 
						std::clamp(b * f, 0.0f, 1.0f), 
						std::clamp(a * f, 0.0f, 1.0f));
	};

	Color4 operator *(const Color4& other) const
	{
		return Color4(
						std::clamp(r * other.r, 0.0f, 1.0f), 
						std::clamp(g * other.g, 0.0f, 1.0f), 
						std::clamp(b * other.b, 0.0f, 1.0f), 
						std::clamp(a * other.a, 0.0f, 1.0f));
	};

};

struct Color3 {

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	Color3() = default;

	Color3(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	Color3(Color4 other)
	{
		this->r = other.r;
		this->g = other.g;
		this->b = other.b;
	}

	Color3 operator +(const Color3& other) const
	{
		return Color3(
					std::clamp(r + other.r, 0.0f, 1.0f), 
					std::clamp(g + other.g, 0.0f, 1.0f), 
					std::clamp(b + other.b, 0.0f, 1.0f));
	};

	Color3 operator *(float f) const
	{
		return Color3(
					std::clamp(r * f, 0.0f, 1.0f), 
					std::clamp(g * f, 0.0f, 1.0f), 
					std::clamp(b * f, 0.0f, 1.0f));
	};

	Color3 operator *(const Color3& other) const
	{
		return Color3(
					std::clamp(r * other.r, 0.0f, 1.0f), 
					std::clamp(g * other.g, 0.0f, 1.0f), 
					std::clamp(b * other.b, 0.0f, 1.0f));
	};

	Color3 operator =(const Color4& other) const
	{
		return Color3(other.r, other.g, other.b);
	}
};