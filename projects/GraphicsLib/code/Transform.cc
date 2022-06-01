#include "Transform.h"

void Transform::Move(Vector3 dir) {
	translation[0][3] += dir.x;
	translation[1][3] += dir.y;
	translation[2][3] += dir.z;
	TransformUpdate();
}

void Transform::SetPos(Vector3 pos) {
	translation[0][3] = pos.x;
	translation[1][3] = pos.y;
	translation[2][3] = pos.z;
	TransformUpdate();
}

Vector3 Transform::GetPos()
{
	Vector3 pos(translation[0][3], translation[1][3], translation[2][3]);
	return pos;
}

void Transform::RotateX(float rad) {
	this->rotationX.RotationX(rad);
	TransformUpdate();
}

void Transform::RotateY(float rad) {
	this->rotationY.RotationY(rad);
	TransformUpdate();
}

void Transform::RotateZ(float rad) {
	this->rotation.RotationZ(rad);
	TransformUpdate();
}

void Transform::RotateAxis(float rad, Vector3 axis) {
	rotationAxis.RotationVector(rad, axis);
	TransformUpdate();
}

void Transform::SetScale(Vector3 S) {
	scale[0][0] = S.x;
	scale[1][1] = S.y;
	scale[2][2] = S.z;
	TransformUpdate();
}

void Transform::TransformUpdate() {
	rotation = rotationX * rotationY * rotationZ * rotationAxis;
	_transform = translation * scale * rotation;
}