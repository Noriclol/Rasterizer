#include "Camera.h"



//Camera::Camera() {
//	Perspective.ProjectionPerspec(0.005f, 150.0f, 75.0f);
//	near = 0.005f;
//	far = 150.f;
//	direction = Vector3::forward;
//}

Camera::Camera(float near, float far, float fov)
{
	this->near = near;
	this->far = far;
	this->fov = fov;
	Perspective.ProjectionPerspec(near, far, fov);
	direction = Vector3::forward;
	LookAt(direction);
}

void Camera::LookAt()
{
	View.LookAt(position, Vector3::zero, Vector3::up);
}

void Camera::LookAt(Vector3 LookPosition)
{
	View.LookAt(position,  LookPosition, Vector3::up);
}

//Matrix4 Camera::GetView() {
//	Matrix4 vp = Perspective * View;
//	return vp;
//}
//
//void Camera::SetView() {
//	Matrix4 vp = Perspective * View;
//}
