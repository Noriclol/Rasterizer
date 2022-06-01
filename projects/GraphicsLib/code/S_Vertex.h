#pragma once

#include <cstring>
#include "Vector3.h"
#include "S_Color.h"


struct  Vertex {

	Vector3 position;
	Vector3 normal;
	Vector3 uv;

	Vertex()
	{
		this->position = Vector3::zero;
		this->normal = Vector3::zero;
		this->uv = Vector3::zero;
	}

	Vertex(const Vector3& pos, const Vector3& norm, const Vector3& uv)
	{
		this->position = pos;
		this->normal = norm;
		this->uv = uv;
	}

	bool operator<(const Vertex& other) const
	{
		return (memcmp((void*)this, (void*)&other, sizeof(Vertex)) > 0);
	}

};
