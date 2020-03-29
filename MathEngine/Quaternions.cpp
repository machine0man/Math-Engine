#include "Quaternions.h"
#include "Vectors.h"
#include "Constants.h"
namespace machineman
{
#pragma region Constructors
	Quaternion::Quaternion() :s(0.0f) {}
	Quaternion::Quaternion(float ts, const Vector3d& tv) : s(ts), v(tv) {}
	Quaternion::Quaternion(const Quaternion& q)
	{
		s = q.s;
		v = q.v;
	}
	Quaternion& Quaternion::operator = (const Quaternion& q)
	{
		s = q.s;
		v = q.v;
		return *this;
	}

#pragma endregion

#pragma region Addition / Subtraction
	void Quaternion::operator+= (const Quaternion& q)
	{
		s += q.s;
		v += q.v;
	}
	Quaternion Quaternion::operator + (const Quaternion& q)const
	{
		return Quaternion(s + q.s, v + q.v);
	}
	void Quaternion::operator-= (const Quaternion& q)
	{
		s -= q.s;
		v -= q.v;
	}
	Quaternion Quaternion::operator - (const Quaternion& q)const
	{
		return Quaternion(s - q.s, v - q.v);
	}
#pragma endregion

#pragma region Multiplication
	Quaternion Quaternion::operator * (const Quaternion& q)const
	{
		return Quaternion(s * q.s - v * q.v, v * q.s + q.v * s + v % q.v);
		//  q1 * q2 =   [(s * q.s) - v.dot(q.v) , (v * q.s) + (q.v * s) + v.cross(q.v)]
		//[scalar , vector ]
	}
	Quaternion Quaternion::multiply(const Quaternion& q)const
	{
		return Quaternion(s * q.s - v * q.v, v * q.s + q.v * s + v % q.v);
	}
	void Quaternion::operator *= (const Quaternion& q)
	{
		(*this) = multiply(q);
	}

#pragma endregion

#pragma region Scalar Multiplication
	void Quaternion::operator *= (float ts)
	{
		s *= ts;
		v *= ts;
	}
	Quaternion Quaternion::operator * (float ts)const
	{
		return Quaternion(s * ts, v * ts);
	}

#pragma endregion

#pragma region Norm/Magnitude , Normalization & Unit-Norm Quaternion
	float Quaternion::norm()const
	{
		return sqrt(s * s + v * v);
	}
	Quaternion Quaternion::normalized()const
	{
		if (norm() != 0)
		{
			float inorm = 1.0f / norm();
			return Quaternion(s * inorm, v * inorm);
		}
	}
	void Quaternion::normalize()
	{
		if (norm() != 0)
		{
			float inorm = 1.0f / norm();
			s *= inorm;
			v *= inorm;
		}
	}
	void Quaternion::convertToUnitNormQuaternion() {

		float angle = DegreesToRad(s);
		std::cout << angle<<std::endl;
		v.normalize();
		s = cosf(angle * 0.5f);
		v = v * sinf(angle * 0.5f);   //Converted to Unit Norm Quaternion
	}

#pragma endregion

#pragma region Conjugate & Inverse
	Quaternion Quaternion::conjugate()
	{
		return Quaternion(s, v * (-1));
	}
	Quaternion Quaternion::inverse()
	{
		float absVal = norm();
		absVal = 1.0f / (absVal * absVal);
		return Quaternion(s * absVal, v * absVal * (-1));

		//Inverse = conjugate(q)/(||q||^2) where q is quaternion and ||q|| is its norm/mag
	}

#pragma endregion

#pragma region Destructor
	Quaternion::~Quaternion() {}
#pragma endregion

#pragma region Display + Helping Func
	void Quaternion::Print()
	{
		std::cout << "( " << s << " ," << v.x << " ," << v.y << " ," << v.z << " )\n";
	}
#pragma endregion





}