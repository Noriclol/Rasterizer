#pragma once
#include <math.h>
#include "Vector3.h"

#define DEG2RAD 0.01745329251994329576923690768489f

/**
 * This class represents a 4 x 4 Matrix and is meant to be used in the creation of graphics.
 *
 *
 *
 *
 */
class Matrix4
{
	friend class Vector3;

protected:
	float mat[4][4];


public:

	static const Matrix4 identity;

	/// <summary>
	/// Multiply Vector3 by Matrix4.
	/// </summary>
	/// <returns>Vector3</returns>
	Vector3 operator*(const Vector3& v)
	{
		Vector3 newVec;
		newVec.x = (mat[0][0] * v.x) + (mat[0][1] * v.y) + (mat[0][2] * v.z) + (mat[0][3] * v.w);
		newVec.y = (mat[1][0] * v.x) + (mat[1][1] * v.y) + (mat[1][2] * v.z) + (mat[1][3] * v.w);
		newVec.z = (mat[2][0] * v.x) + (mat[2][1] * v.y) + (mat[2][2] * v.z) + (mat[2][3] * v.w);
		newVec.w = (mat[3][0] * v.x) + (mat[3][1] * v.y) + (mat[3][2] * v.z) + (mat[3][3] * v.w);
		return newVec;
	}


	Matrix4 operator*=(const Vector3& v)
	{
		Matrix4 m;

		for (auto& i : mat)
		{
			for (float& j : i)
			{
				j *= v.length();
			}
		}

		return m;
	}

	/// <summary>
	/// Multiply Matrix4 by Matrix4.
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Matrix4 operator*(const Matrix4& other) const
	{
		Matrix4 newMat;
		//row 1, col 1,2,3,4
		newMat.mat[0][0] = mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0] + mat[0][2] * other.mat[2][0] + mat[0][3] * other.mat[3][0];
		newMat.mat[0][1] = mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1] + mat[0][2] * other.mat[2][1] + mat[0][3] * other.mat[3][1];
		newMat.mat[0][2] = mat[0][0] * other.mat[0][2] + mat[0][1] * other.mat[1][2] + mat[0][2] * other.mat[2][2] + mat[0][3] * other.mat[3][2];
		newMat.mat[0][3] = mat[0][0] * other.mat[0][3] + mat[0][1] * other.mat[1][3] + mat[0][2] * other.mat[2][3] + mat[0][3] * other.mat[3][3];
		//row 2, col 1,2,3,4
		newMat.mat[1][0] = mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0] + mat[1][2] * other.mat[2][0] + mat[1][3] * other.mat[3][0];
		newMat.mat[1][1] = mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1] + mat[1][2] * other.mat[2][1] + mat[1][3] * other.mat[3][1];
		newMat.mat[1][2] = mat[1][0] * other.mat[0][2] + mat[1][1] * other.mat[1][2] + mat[1][2] * other.mat[2][2] + mat[1][3] * other.mat[3][2];
		newMat.mat[1][3] = mat[1][0] * other.mat[0][3] + mat[1][1] * other.mat[1][3] + mat[1][2] * other.mat[2][3] + mat[1][3] * other.mat[3][3];
		//row 3, col 1,2,3,4
		newMat.mat[2][0] = mat[2][0] * other.mat[0][0] + mat[2][1] * other.mat[1][0] + mat[2][2] * other.mat[2][0] + mat[2][3] * other.mat[3][0];
		newMat.mat[2][1] = mat[2][0] * other.mat[0][1] + mat[2][1] * other.mat[1][1] + mat[2][2] * other.mat[2][1] + mat[2][3] * other.mat[3][1];
		newMat.mat[2][2] = mat[2][0] * other.mat[0][2] + mat[2][1] * other.mat[1][2] + mat[2][2] * other.mat[2][2] + mat[2][3] * other.mat[3][2];
		newMat.mat[2][3] = mat[2][0] * other.mat[0][3] + mat[2][1] * other.mat[1][3] + mat[2][2] * other.mat[2][3] + mat[2][3] * other.mat[3][3];
		//row 4, col 1,2,3,4
		newMat.mat[3][0] = mat[3][0] * other.mat[0][0] + mat[3][1] * other.mat[1][0] + mat[3][2] * other.mat[2][0] + mat[3][3] * other.mat[3][0];
		newMat.mat[3][1] = mat[3][0] * other.mat[0][1] + mat[3][1] * other.mat[1][1] + mat[3][2] * other.mat[2][1] + mat[3][3] * other.mat[3][1];
		newMat.mat[3][2] = mat[3][0] * other.mat[0][2] + mat[3][1] * other.mat[1][2] + mat[3][2] * other.mat[2][2] + mat[3][3] * other.mat[3][2];
		newMat.mat[3][3] = mat[3][0] * other.mat[0][3] + mat[3][1] * other.mat[1][3] + mat[3][2] * other.mat[2][3] + mat[3][3] * other.mat[3][3];

		return newMat;
	}

	/// <summary>
	/// Multiply Matrix4 by scalar value.
	/// </summary>
	/// <returns>Matrix4</returns>
	Matrix4 operator*(const float scalar) const
	{
		Matrix4 newMat;
		//row 1, col 1,2,3,4
		newMat.mat[0][0] = mat[0][0] * scalar;
		newMat.mat[0][1] = mat[0][1] * scalar;
		newMat.mat[0][2] = mat[0][2] * scalar;
		newMat.mat[0][3] = mat[0][3] * scalar;
		//row 2, col 1,2,3,4
		newMat.mat[1][0] = mat[1][0] * scalar;
		newMat.mat[1][1] = mat[1][1] * scalar;
		newMat.mat[1][2] = mat[1][2] * scalar;
		newMat.mat[1][3] = mat[1][3] * scalar;
		//row 3, col 1,2,3,4
		newMat.mat[2][0] = mat[2][0] * scalar;
		newMat.mat[2][1] = mat[2][1] * scalar;
		newMat.mat[2][2] = mat[2][2] * scalar;
		newMat.mat[2][3] = mat[2][3] * scalar;
		//row 4, col 1,2,3,4
		newMat.mat[3][0] = mat[3][0] * scalar;
		newMat.mat[3][1] = mat[3][1] * scalar;
		newMat.mat[3][2] = mat[3][2] * scalar;
		newMat.mat[3][3] = mat[3][3] * scalar;
		return newMat;
	}

	Matrix4& operator=(const Matrix4& other)
	{
		//row 1, col 1,2,3,4
		mat[0][0] = other.mat[0][0];
		mat[0][1] = other.mat[0][1];
		mat[0][2] = other.mat[0][2];
		mat[0][3] = other.mat[0][3];
		//row 2, col 1,2,3,4
		mat[1][0] = other.mat[1][0];
		mat[1][1] = other.mat[1][1];
		mat[1][2] = other.mat[1][2];
		mat[1][3] = other.mat[1][3];
		//row 3, col 1,2,3,4
		mat[2][0] = other.mat[2][0];
		mat[2][1] = other.mat[2][1];
		mat[2][2] = other.mat[2][2];
		mat[2][3] = other.mat[2][3];
		//row 4, col 1,2,3,4
		mat[3][0] = other.mat[3][0];
		mat[3][1] = other.mat[3][1];
		mat[3][2] = other.mat[3][2];
		mat[3][3] = other.mat[3][3];
		return *this;
	}

	/// <summary>
	/// Operator Overload to acces matrix by [][]. Read only
	/// </summary>
	/// <returns>float</returns>
	const float* operator[](int i) const
	{
		// read
		if (i < 4 && i >= 0)
		{
			return mat[i];
		}
		throw("index out of bounds");
	}

	/// <summary>
	/// Operator Overload to acces matrix by [][]. Write only
	/// </summary>
	/// <returns>float</returns>
	float* operator[](int i)
	{
		// write
		if (i < 4 && i >= 0) {
			return mat[i];
		}
		throw("index out of bounds");
	}

	/// <summary>
	/// Create rotation Matrix4 around the X axis by Float.
	/// </summary>
	/// <param name="rad">amount of degrees to rotate something.</param>
	void RotationX(float rad)
	{
		mat[1][1] = cosf(rad);
		mat[1][2] = -sinf(rad);
		mat[2][1] = sinf(rad);
		mat[2][2] = cosf(rad);
	}

	/// <summary>
	/// Create rotation Matrix4 around the Y axis by Float.
	/// </summary>
	/// <param name="rad">amount of degrees to rotate something.</param>
	void RotationY(float rad)
	{
		mat[0][0] = cosf(rad);
		mat[0][2] = sinf(rad);
		mat[2][0] = -sinf(rad);
		mat[2][2] = cosf(rad);
	}

	/// <summary>
	/// Create rotation Matrix4 around the Z axis by Float.
	/// </summary>
	/// <param name="rad">amount of degrees to rotate something.</param>
	void RotationZ(float rad)
	{
		mat[0][0] = cosf(rad);
		mat[0][1] = -sinf(rad);
		mat[1][0] = sinf(rad);
		mat[1][1] = cosf(rad);
	}

	void AddRotationX(float rad)
	{
		mat[1][1] += cosf(rad);
		mat[1][2] += -sinf(rad);
		mat[2][1] += sinf(rad);
		mat[2][2] += cosf(rad);
	}

	/// <summary>
	/// Create rotation Matrix4 around the Y axis by Float.
	/// </summary>
	/// <param name="rad">amount of degrees to rotate something.</param>
	void AddRotationY(float rad)
	{
		mat[0][0] += cosf(rad);
		mat[0][2] += sinf(rad);
		mat[2][0] += -sinf(rad);
		mat[2][2] += cosf(rad);
	}

	/// <summary>
	/// Create rotation Matrix4 around the Z axis by Float.
	/// </summary>
	/// <param name="rad">amount of degrees to rotate something.</param>
	void AddRotationZ(float rad)
	{
		mat[0][0] += cosf(rad);
		mat[0][1] += -sinf(rad);
		mat[1][0] += sinf(rad);
		mat[1][1] += cosf(rad);
	}

	/// <summary>
	/// Rotate Matrix4 around Vector3 Pivot
	/// </summary>
	/// <param name="rad"></param>
	void RotationVector(float rad, Vector3 vec)
	{
		Vector3 nVec = vec.normalize();
		float v1 = (1.0f - cosf(rad));
		float ux = (nVec.x * nVec.x);
		float uy = (nVec.y * nVec.y);
		float uz = (nVec.z * nVec.z);
		float x = nVec.x;
		float y = nVec.y;
		float z = nVec.z;

		//row 1, col 1,2,3,4
		mat[0][0] = cosf(rad) + ux * v1;
		mat[0][1] = x * y * v1 - z * sinf(rad);
		mat[0][2] = x * z * v1 + y * sinf(rad);
		mat[0][3] = 0.0f;
		//row 2, col 1,2,3,4
		mat[1][0] = y * x * v1 + z * sinf(rad);
		mat[1][1] = cosf(rad) + uy * v1;
		mat[1][2] = y * z * v1 - x * sinf(rad);
		mat[1][3] = 0.0f;
		//row 3, col 1,2,3,4
		mat[2][0] = z * x * v1 - y * sinf(rad);
		mat[2][1] = z * y * v1 + x * sinf(rad);
		mat[2][2] = cosf(rad) + uz * v1;
		mat[2][3] = 0.0f;
		//row 4, col 1,2,3,4
		mat[3][0] = 0.0f;
		mat[3][1] = 0.0f;
		mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}


	void Translate(Vector3& v)
	{
		mat[0][3] += v[0];
		mat[1][3] += v[1];
		mat[2][3] += v[2];
	}

	/// <summary>
	/// orthographic projection(not tested once)
	/// </summary>
	void ProjectionOrtho(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
	{
		//left, right, bottom, top, far, near.

		//row 1, col 1,2,3,4
		mat[0][0] = 2 / (minX - maxX);
		mat[0][1] = 0.0f;
		mat[0][2] = 0.0f;
		mat[0][3] = -(maxX + minX) / (maxX - minX);
		//row 1, col 1,2,3,4
		mat[1][0] = 0.0f;
		mat[1][1] = 2 / (maxY - minY);
		mat[1][2] = 0.0f;
		mat[1][3] = -(maxY + minY) / (maxY - minY);
		//row 1, col 1,2,3,4
		mat[2][0] = 0.0f;
		mat[2][1] = 0.0f;
		mat[2][2] = -2 / (minZ - maxZ);
		mat[2][3] = -(minZ + maxZ) / (minZ + maxZ);
		//row 1, col 1,2,3,4
		mat[3][0] = 0.0f;
		mat[3][1] = 0.0f;
		mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
		//row 1, col 1,2,3,4
	}

	/// <summary>
	/// Perspective Projection(works like a charm)
	/// </summary>
	void ProjectionPerspec(float near, float far, float fov)
	{
		float S = 1 / (tanf((fov * 0.5f) * DEG2RAD));

		mat[0][0] = S;
		mat[0][1] = 0.0f;
		mat[0][2] = 0.0f;
		mat[0][3] = 0.0f;

		mat[1][0] = 0.0f;
		mat[1][1] = S;
		mat[1][2] = 0.0f;
		mat[1][3] = 0.0f;

		mat[2][0] = 0.0f;
		mat[2][1] = 0.0f;
		mat[2][2] = -far / (far - near);
		mat[2][3] = -far * near / (far - near);

		mat[3][0] = 0.0f;
		mat[3][1] = 0.0f;
		mat[3][2] = -1.0f;
		mat[3][3] = 0.0f;
	}

	void ProjectionPerspecT(float near, float far, float fov)
	{
		float S = 1 / (tanf((fov * 0.5f) * DEG2RAD));

		mat[0][0] = S;
		mat[1][0] = 0.0f;
		mat[2][0] = 0.0f;
		mat[3][0] = 0.0f;

		mat[0][1] = 0.0f;
		mat[1][1] = S;
		mat[2][1] = 0.0f;
		mat[3][1] = 0.0f;

		mat[0][2] = 0.0f;
		mat[1][2] = 0.0f;
		mat[2][2] = -far / (far - near);
		mat[3][2] = -far * near / (far - near);

		mat[0][3] = 0.0f;
		mat[1][3] = 0.0f;
		mat[2][3] = -1.0f;
		mat[3][3] = 0.0f;
	}

	void ProjectionPerspecAspect(float aspect, float near, float far, float fov)
	{
		const float t = tanf(fov / (2 * DEG2RAD)) * near;
		const float l = -t * aspect;
		const float r = t * aspect;
		const float b = l;

		//const float tanFOV = tan(fov * 0.5f);
		//const float cotFOVinvA = 1 / (tanFOV * aspect);
		//const float cotFOV = 1 / (tanFOV);


		////mat[0][0] = near / r;
		//mat[0][0] = cotFOVinvA;
		//mat[0][1] = 0.0f;
		//mat[0][2] = 0.0f;
		//mat[0][3] = 0.0f;

		//mat[1][0] = 0.0f;
		////mat[1][1] = near / t;
		//mat[1][1] = cotFOV;
		//mat[1][2] = 0.0f;
		//mat[1][3] = 0.0f;

		//mat[2][0] = 0.0f;
		//mat[2][1] = 0.0f;
		//mat[2][2] = -(far + near) / (far - near);
		//mat[2][3] = ( - 2 * far * near) / (far - near);

		//mat[3][0] = 0.0f;
		//mat[3][1] = 0.0f;
		//mat[3][2] = -1.0f;
		//mat[3][3] = 0.0f;


		mat[0][0] = 2 * near / (r - l);
		mat[0][1] = 0.0f;
		mat[0][2] = (r + l) / (r - l);
		mat[0][3] = 0.0f;

		mat[1][0] = 0.0f;
		mat[1][1] = 2 * near / (t - b);
		mat[1][2] = (t + b) / (t - b);
		mat[1][3] = 0.0f;

		mat[2][0] = 0.0f;
		mat[2][1] = 0.0f;
		mat[2][2] = -(far + near) / (far - near);
		mat[2][3] = (-2 * far * near) / (far - near);

		mat[3][0] = 0.0f;
		mat[3][1] = 0.0f;
		mat[3][2] = -1.0f;
		mat[3][3] = 0.0f;

	}


	/// <summary>
	/// LookAt function for the camera by creating a matrix oriented towards the target from the current position.
	/// </summary>
	/// <param name="pos">camera position</param>
	/// <param name="target">target position</param>
	/// <param name="up">world up vector. default is Vector3(0.0f, 1.0f ,0.0f)</param>
	void LookAt(const Vector3& pos, const Vector3& target, const Vector3& up)
	{
		Vector3 _target = target;
		Vector3 _pos = pos;
		Vector3 _up = up;
		Vector3 forward = (_pos - target).normalize();

		Vector3 right = _up.CrossProduct(forward).normalize();
		Vector3 up2 = forward.CrossProduct(right).normalize();

		View(pos, forward, up2, right);
	}

	/// <summary>
	/// view function creates a matrix using a position, and forward, right and up vectors.
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="forward"></param>
	/// <param name="up"></param>
	/// <param name="right"></param>
	void View(Vector3 pos, Vector3 forward, Vector3 up, Vector3 right)
	{
		mat[0][0] = right.x;
		mat[0][1] = right.y;
		mat[0][2] = right.z;
		mat[0][3] = -(right.DotProduct(pos));
		mat[1][0] = up.x;
		mat[1][1] = up.y;
		mat[1][2] = up.z;
		mat[1][3] = -(up.DotProduct(pos));
		mat[2][0] = forward.x;
		mat[2][1] = forward.y;
		mat[2][2] = forward.z;
		mat[2][3] = -(forward.DotProduct(pos));
		mat[3][0] = 0.0f;
		mat[3][1] = 0.0f;
		mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}

	/// <summary>
	/// Function to calculate the determinant of a Matrix4.
	/// </summary>
	/// <returns>float</returns>
	float Determinant()
	{
		float value;
		value =
			mat[0][3] * mat[1][2] * mat[2][1] * mat[3][0] - mat[0][2] * mat[1][3] * mat[2][1] * mat[3][0] -
			mat[0][3] * mat[1][1] * mat[2][2] * mat[3][0] + mat[0][1] * mat[1][3] * mat[2][2] * mat[3][0] +
			mat[0][2] * mat[1][1] * mat[2][3] * mat[3][0] - mat[0][1] * mat[1][2] * mat[2][3] * mat[3][0] -
			mat[0][3] * mat[1][2] * mat[2][0] * mat[3][1] + mat[0][2] * mat[1][3] * mat[2][0] * mat[3][1] +
			mat[0][3] * mat[1][0] * mat[2][2] * mat[3][1] - mat[0][0] * mat[1][3] * mat[2][2] * mat[3][1] -
			mat[0][2] * mat[1][0] * mat[2][3] * mat[3][1] + mat[0][0] * mat[1][2] * mat[2][3] * mat[3][1] +
			mat[0][3] * mat[1][1] * mat[2][0] * mat[3][2] - mat[0][1] * mat[1][3] * mat[2][0] * mat[3][2] -
			mat[0][3] * mat[1][0] * mat[2][1] * mat[3][2] + mat[0][0] * mat[1][3] * mat[2][1] * mat[3][2] +
			mat[0][1] * mat[1][0] * mat[2][3] * mat[3][2] - mat[0][0] * mat[1][1] * mat[2][3] * mat[3][2] -
			mat[0][2] * mat[1][1] * mat[2][0] * mat[3][3] + mat[0][1] * mat[1][2] * mat[2][0] * mat[3][3] +
			mat[0][2] * mat[1][0] * mat[2][1] * mat[3][3] - mat[0][0] * mat[1][2] * mat[2][1] * mat[3][3] -
			mat[0][1] * mat[1][0] * mat[2][2] * mat[3][3] + mat[0][0] * mat[1][1] * mat[2][2] * mat[3][3];
		if (value != 0)
		{
			return value;
		}
		return 1.0f;
	}

	/// <summary>
	/// Function to calculate the inverse of a Matrix4.
	/// </summary>
	/// <returns>Matrix4</returns>
	Matrix4 Inverse()
	{
		Matrix4 newMat;
		newMat[0][0] = mat[1][2] * mat[2][3] * mat[3][1] - mat[1][3] * mat[2][2] * mat[3][1] + mat[1][3] * mat[2][1] * mat[3][2] - mat[1][1] * mat[2][3] * mat[3][2] - mat[1][2] * mat[2][1] * mat[3][3] + mat[1][1] * mat[2][2] * mat[3][3];
		newMat[0][1] = mat[0][3] * mat[2][2] * mat[3][1] - mat[0][2] * mat[2][3] * mat[3][1] - mat[0][3] * mat[2][1] * mat[3][2] + mat[0][1] * mat[2][3] * mat[3][2] + mat[0][2] * mat[2][1] * mat[3][3] - mat[0][1] * mat[2][2] * mat[3][3];
		newMat[0][2] = mat[0][2] * mat[1][3] * mat[3][1] - mat[0][3] * mat[1][2] * mat[3][1] + mat[0][3] * mat[1][1] * mat[3][2] - mat[0][1] * mat[1][3] * mat[3][2] - mat[0][2] * mat[1][1] * mat[3][3] + mat[0][1] * mat[1][2] * mat[3][3];
		newMat[0][3] = mat[0][3] * mat[1][2] * mat[2][1] - mat[0][2] * mat[1][3] * mat[2][1] - mat[0][3] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][3] * mat[2][2] + mat[0][2] * mat[1][1] * mat[2][3] - mat[0][1] * mat[1][2] * mat[2][3];
		newMat[1][0] = mat[1][3] * mat[2][2] * mat[3][0] - mat[1][2] * mat[2][3] * mat[3][0] - mat[1][3] * mat[2][0] * mat[3][2] + mat[1][0] * mat[2][3] * mat[3][2] + mat[1][2] * mat[2][0] * mat[3][3] - mat[1][0] * mat[2][2] * mat[3][3];
		newMat[1][1] = mat[0][2] * mat[2][3] * mat[3][0] - mat[0][3] * mat[2][2] * mat[3][0] + mat[0][3] * mat[2][0] * mat[3][2] - mat[0][0] * mat[2][3] * mat[3][2] - mat[0][2] * mat[2][0] * mat[3][3] + mat[0][0] * mat[2][2] * mat[3][3];
		newMat[1][2] = mat[0][3] * mat[1][2] * mat[3][0] - mat[0][2] * mat[1][3] * mat[3][0] - mat[0][3] * mat[1][0] * mat[3][2] + mat[0][0] * mat[1][3] * mat[3][2] + mat[0][2] * mat[1][0] * mat[3][3] - mat[0][0] * mat[1][2] * mat[3][3];
		newMat[1][3] = mat[0][2] * mat[1][3] * mat[2][0] - mat[0][3] * mat[1][2] * mat[2][0] + mat[0][3] * mat[1][0] * mat[2][2] - mat[0][0] * mat[1][3] * mat[2][2] - mat[0][2] * mat[1][0] * mat[2][3] + mat[0][0] * mat[1][2] * mat[2][3];
		newMat[2][0] = mat[1][1] * mat[2][3] * mat[3][0] - mat[1][3] * mat[2][1] * mat[3][0] + mat[1][3] * mat[2][0] * mat[3][1] - mat[1][0] * mat[2][3] * mat[3][1] - mat[1][1] * mat[2][0] * mat[3][3] + mat[1][0] * mat[2][1] * mat[3][3];
		newMat[2][1] = mat[0][3] * mat[2][1] * mat[3][0] - mat[0][1] * mat[2][3] * mat[3][0] - mat[0][3] * mat[2][0] * mat[3][1] + mat[0][0] * mat[2][3] * mat[3][1] + mat[0][1] * mat[2][0] * mat[3][3] - mat[0][0] * mat[2][1] * mat[3][3];
		newMat[2][2] = mat[0][1] * mat[1][3] * mat[3][0] - mat[0][3] * mat[1][1] * mat[3][0] + mat[0][3] * mat[1][0] * mat[3][1] - mat[0][0] * mat[1][3] * mat[3][1] - mat[0][1] * mat[1][0] * mat[3][3] + mat[0][0] * mat[1][1] * mat[3][3];
		newMat[2][3] = mat[0][3] * mat[1][1] * mat[2][0] - mat[0][1] * mat[1][3] * mat[2][0] - mat[0][3] * mat[1][0] * mat[2][1] + mat[0][0] * mat[1][3] * mat[2][1] + mat[0][1] * mat[1][0] * mat[2][3] - mat[0][0] * mat[1][1] * mat[2][3];
		newMat[3][0] = mat[1][2] * mat[2][1] * mat[3][0] - mat[1][1] * mat[2][2] * mat[3][0] - mat[1][2] * mat[2][0] * mat[3][1] + mat[1][0] * mat[2][2] * mat[3][1] + mat[1][1] * mat[2][0] * mat[3][2] - mat[1][0] * mat[2][1] * mat[3][2];
		newMat[3][1] = mat[0][1] * mat[2][2] * mat[3][0] - mat[0][2] * mat[2][1] * mat[3][0] + mat[0][2] * mat[2][0] * mat[3][1] - mat[0][0] * mat[2][2] * mat[3][1] - mat[0][1] * mat[2][0] * mat[3][2] + mat[0][0] * mat[2][1] * mat[3][2];
		newMat[3][2] = mat[0][2] * mat[1][1] * mat[3][0] - mat[0][1] * mat[1][2] * mat[3][0] - mat[0][2] * mat[1][0] * mat[3][1] + mat[0][0] * mat[1][2] * mat[3][1] + mat[0][1] * mat[1][0] * mat[3][2] - mat[0][0] * mat[1][1] * mat[3][2];
		newMat[3][3] = mat[0][1] * mat[1][2] * mat[2][0] - mat[0][2] * mat[1][1] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1] - mat[0][0] * mat[1][2] * mat[2][1] - mat[0][1] * mat[1][0] * mat[2][2] + mat[0][0] * mat[1][1] * mat[2][2];
		return newMat * (1.0f / Determinant());
	}

	/// <summary>
	/// Function to Transpose a Matrix4.
	/// </summary>
	/// <returns></returns>
	Matrix4 Transpose()
	{
		Matrix4 newmat;
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				newmat.mat[i][j] = mat[j][i];
			}
		}
		return newmat;
	}

	/// <summary>
	/// Empty constructor. All fields will be 0;
	/// </summary>
	Matrix4() :
		mat{
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		}
	{
	}

	/// <summary>
	/// Identity Matrix4 Constructor
	/// </summary>
	/// <param name="val">if yes it will construct a identity Matrix4</param>

	/// <summary>
	/// Copy constructor for Matrix4.
	/// </summary>
	/// <param name="other"></param>
	Matrix4(const Matrix4& other)
	{
		//row 1, col 1,2,3,4
		mat[0][0] = other.mat[0][0];
		mat[0][1] = other.mat[0][1];
		mat[0][2] = other.mat[0][2];
		mat[0][3] = other.mat[0][3];
		//row 2, col 1,2,3,4
		mat[1][0] = other.mat[1][0];
		mat[1][1] = other.mat[1][1];
		mat[1][2] = other.mat[1][2];
		mat[1][3] = other.mat[1][3];
		//row 3, col 1,2,3,4
		mat[2][0] = other.mat[2][0];
		mat[2][1] = other.mat[2][1];
		mat[2][2] = other.mat[2][2];
		mat[2][3] = other.mat[2][3];
		//row 4, col 1,2,3,4
		mat[3][0] = other.mat[3][0];
		mat[3][1] = other.mat[3][1];
		mat[3][2] = other.mat[3][2];
		mat[3][3] = other.mat[3][3];
	};
private:
	static Matrix4 IdentityMatrix4()
	{
		//identity matrix
		Matrix4 newmat;
		for (unsigned int i = 0; i < 4; i++)
		{
			newmat[i][i] = 1.0f;
		}
		return newmat;
	}
};
