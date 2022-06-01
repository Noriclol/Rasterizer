#pragma once
#include <math.h>

class Matrix4;
class Vector3 {
	friend class Matrix4;
protected:
	
public:
	float x, y, z, w;
	static const Vector3 zero;
	static const Vector3 forward;
	static const Vector3 up;
	static const Vector3 right;
	//array operator
	/// <summary>
	/// Array operator overload. with the intent of enabling access to the x,y, z, w variables.
	/// </summary>
	/// <param name="i">index</param>
	/// <returns>x,y,z or w</returns>
	const float& operator[](int i) const { // read
		switch (i) {
		case 0: return x; break;
		case 1: return y; break;
		case 2: return z; break;
		case 3: return w; break;
		default: throw "Index out of range"; break;
		}
	}
	float& operator[](int i) { // write
		switch (i) {
		case 0: return x; break;
		case 1: return y; break;
		case 2: return z; break;
		case 3: return w; break;
		default: throw "Index out of range"; break;
		}
	}
	//additon on points
	Vector3 operator+(const Vector3& other) {
		Vector3 newVec;
		newVec.x = x + other.x;
		newVec.y = y + other.y;
		newVec.z = z + other.z;
		return newVec;
	};
	Vector3& operator+=(const Vector3& other) {
		x = x + other.x;
		y = y + other.y;
		z = z + other.z;
		return *this;
	}

	//subtraction on points
	Vector3 operator-(const Vector3& other) {
		Vector3 newVec;
		newVec.x = x - other.x;
		newVec.y = y - other.y;
		newVec.z = z - other.z;
		return newVec;
	}
	//subtraction on points
	Vector3& operator-=(const Vector3& other) {
		Vector3 newVec;
		newVec.x = x - other.x;
		newVec.y = y - other.y;
		newVec.z = z - other.z;
		return *this;
	}
	/// <summary>
	/// Calculates dot product between 2 Vector3 returning a float.
	/// </summary>
	/// <param name="other">other vector3</param>
	/// <returns>float</returns>
	float DotProduct(const Vector3& other) const {
		return ((x * other.x) + (y * other.y) + (z * other.z)); }
	/// <summary>
	/// Calculates cross product.
	/// </summary>
	/// <param name="other">other Vector3</param>
	/// <returns>Vector3</returns>
	Vector3 CrossProduct(const Vector3& other) {
		Vector3 newVec;
		newVec.x = (y * other.z) - (z * other.y);
		newVec.y = (z * other.x) - (x * other.z);
		newVec.z = (x * other.y) - (y * other.x);
		return newVec;
	}
	/// <summary>
	/// multiplies Vector3 by scalar(float).
	/// </summary>
	/// <param name="scalar">scalar</param>
	/// <returns>Vector3</returns>
	Vector3& operator*(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	/// <summary>
	/// divides Vector3 by scalar(float).
	/// </summary>
	/// <param name="scalar">scalar</param>
	/// <returns>Vector3</returns>
	Vector3& operator/(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	Vector3& operator*=(float scalar) 
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}



	//Operators

	/// <summary>
	/// Sets the values of one vector to those of another.
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Vector3& operator=(const Vector3& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}


	bool operator==(const Vector3& other) const {
		return (x == other.x && y == other.y && z == other.z); 
	}

	bool operator!=(const Vector3& other) const { return (x != other.x || y != other.y || z != other.z); }

	bool operator<(const Vector3& other) const {
		return (x < other.x && y < other.y && z < other.z);
	}

	bool operator>(const Vector3& other) const {
		return (x > other.x && y > other.y && z > other.z);
	}

	/// <summary>
	/// Function to determine length o vector3.
	/// </summary>
	/// <returns>float</returns>
	float length() const
	{
		return sqrtf((x * x) + (y * y) + (z * z));
	}


	/// <summary>
	/// Function to normalize Vector3.
	/// </summary>
	/// <returns>Vector3</returns>
	Vector3 normalize() const {
		Vector3 newVector;
		float len = sqrtf((x * x) + (y * y) + (z * z));
		if (len == 0.0f) { return newVector; }
		newVector[0] = x / len;
		newVector[1] = y / len;
		newVector[2] = z / len;

		return newVector;
	}

	//void print() const {
	//	std::cout << "x: " << x << " y: " << y;
	//}
	
	//constructors
	/// <summary>
	/// empty Vector3 Constructor
	/// </summary>
	Vector3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}



	/// <summary>
	/// Vector3 Copy Constructor
	/// </summary>
	Vector3(const Vector3& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		w = 1.0f;
	}



	/// <summary>
	/// vector constructor taking x and y. good for UVs
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	Vector3(float x, float y) {
		this->x = x;
		this->y = y;
		this->z = 0.0f;
		this->w = 1.0f;
	}



	/// <summary>
	/// vector constructor taking x, y and z
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = 1.0f;
	}
};

