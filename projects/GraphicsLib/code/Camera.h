#pragma once
#include "Matrix4.h"

class Camera {
public:

	Vector3 position = Vector3::zero;
	Vector3 direction;
	Matrix4 Perspective;
	Matrix4 View;

	float near;
	float far;
	float fov;
	float aspect = 0;

	Camera() = default;
	Camera(float near, float far, float fov);

	void LookAt();
	void LookAt(Vector3 position);
	//Matrix4 GetView();
	//void SetView();

	void GetAspectRatio(float Height, float Width);

};