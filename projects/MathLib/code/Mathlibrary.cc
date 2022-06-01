#include "Matrix4.h"
#include "Vector3.h"
// Mathlibrary


	//static definitions

//vector
const Vector3 Vector3::zero = Vector3	(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::forward = Vector3(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::up = Vector3		(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::right = Vector3	(1.0f, 0.0f, 0.0f);

//matrix
const Matrix4 Matrix4::identity = IdentityMatrix4();