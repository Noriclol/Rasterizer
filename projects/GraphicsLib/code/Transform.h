#pragma once
#include <vector>
#include "Matrix4.h"

class Transform 
{
private:
	Matrix4 _transform;
	Matrix4 scale;
	Matrix4 translation;

	Matrix4 rotation;
	Matrix4 rotationZ;
	Matrix4 rotationY;
	Matrix4 rotationX;
	Matrix4 rotationAxis;



public:
	Matrix4& transform;
	Transform(): transform(_transform) {}
	~Transform() = default;
	void Move(Vector3 dir);
	void SetPos(Vector3 pos);
	Vector3 GetPos();
	void RotateX(float rad);
	void RotateY(float rad);
	void RotateZ(float rad);
	void RotateAxis(float rad, Vector3 axis);

	void SetScale(Vector3 Scale);

	void TransformUpdate();
};