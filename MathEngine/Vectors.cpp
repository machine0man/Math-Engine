#include "Vectors.h"
#include "Quaternions.h"

namespace machineman
{
#pragma region Constructors

	Vector3d::Vector3d() :x(0.0f), y(0.0f), z(0.0f) {}
	Vector3d::Vector3d(const Vector3d& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	Vector3d::Vector3d(float tx, float ty, float tz)
	{
		x = tx; y = ty; z = tz;
	}
	Vector3d& Vector3d::operator = (const Vector3d& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;     // Need to be understood better LATER


	}
	// Why did *this is returned in Upper Function 
#pragma endregion

#pragma region Destructors
	Vector3d::~Vector3d() {}
#pragma endregion

#pragma region Addition
	Vector3d Vector3d::operator + (Vector3d const& v)const
	{
		Vector3d temp;
		temp.x = x + v.x;
		temp.y = y + v.y;
		temp.z = z + v.z;

		return temp;
	}
	//OR
	/*
	R4DVector3n R4DVector3n::operator+(const R4DVector3n& v)const{
	//Returns a third vector representing the addition of two 3D vectors
	return R4DVector3n(x+v.x,y+v.y,z+v.z);
	}

	*/
	void Vector3d::operator += (const Vector3d& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

#pragma endregion 

#pragma region Subtraction

	Vector3d Vector3d::operator - (Vector3d const& v)const
	{
		Vector3d temp;
		temp.x = x - v.x;
		temp.y = y - v.y;
		temp.z = z - v.z;

		return temp;
	}

	void Vector3d::operator -= (const Vector3d& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
#pragma endregion

#pragma region Scalar Product
	Vector3d Vector3d::operator * (const float n) const {
		return Vector3d(x * n, y * n, z * n);
	}
	void Vector3d::operator *= (const float n) {
		x *= n; y *= n; z *= n;
	}

	Vector3d Vector3d::operator / (const float n) const {
		return Vector3d(x / n, y / n, z / n);
	}
	void Vector3d::operator /= (const float n) {
		x /= n; y /= n; z /= n;
	}
#pragma endregion

#pragma region Dot Product
	float Vector3d::dot(const Vector3d& v)const
	{
		return x * v.x + y * v.y + z * v.z;
	}
	float Vector3d::operator * (const Vector3d& v)const
	{
		return x * v.x + y * v.y + z * v.z;
	}

#pragma endregion

#pragma region Cross Product
	Vector3d Vector3d::cross(const Vector3d& v)const
	{
		return Vector3d(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}
	Vector3d Vector3d::operator % (const Vector3d& v)const
	{
		return Vector3d(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}

#pragma endregion

#pragma region Magnitude & Normalization
	float Vector3d::magnitude()
	{
		return std::sqrt(x * x + y * y + z * z);
	}
	Vector3d Vector3d::normalized()
	{
		float mag = magnitude();
		if (mag > 0.0f)
		{
			float magInversed = 1.0f / mag;
			return Vector3d(x * magInversed, y * magInversed, z * magInversed);
		}
	}
	void Vector3d::normalize()
	{
		float mag = magnitude();
		if (mag > 0.0f)
		{
			float magInversed = 1.0f / mag;
			x *= magInversed;
			y *= magInversed;
			z *= magInversed;
		}
	}

#pragma endregion

#pragma region Vector Rotation
	Vector3d Vector3d::rotateVectorAboutAngleAndAxis(float Angle, Vector3d& Axis)
	{
				
			//convert our vector to a pure quaternion
			Quaternion p(0.0f, (*this));

			//normalize the axis
			Axis.normalize();

			//create the real quaternion
			Quaternion q(Angle, Axis);

			//convert quaternion to unit norm quaternion
			q.convertToUnitNormQuaternion();

			//Get the inverse of the quaternion
			Quaternion qInverse = q.inverse();

			//rotate the quaternion
			Quaternion rotatedVector = q *( p * qInverse);

			//return the vector part of the quaternion
			return rotatedVector.v;
			
	}
#pragma endregion


#pragma region Display
	void Vector3d::Print()
	{
		std::cout << "( " << x << " ," << y << " ," << z << " )\n";
	}
#pragma endregion





}