//Quaternion is used to ease up the calculations
//It is made up of a scalar and a vector
//Vector consists of 3 imaginaries 
//Actually it is a complex no. with 3 imaginaries ,Eg : s + ix + jy + cz where i,j,k similar to "i" 
//in imaginary numbers  
#ifndef Quaternions
#define Quaternions

#include<iostream>
#include "Vectors.h"



namespace machineman{

	class Quaternion
	{
	public:
		float s;
		Vector3d v;

		//Constructors
		Quaternion();
		Quaternion(float ts, const Vector3d& tv);
		Quaternion(const Quaternion& q);
		Quaternion& operator = (const Quaternion& v);

		//Destructor
		~Quaternion();

		//Methods
		void operator += (const Quaternion& q);
		Quaternion operator + (const Quaternion& q)const;
		void operator -=(const Quaternion& q);
		Quaternion operator - (const Quaternion& q)const;
		void operator *= (const Quaternion& q);
		Quaternion operator * (const Quaternion& q)const;
		Quaternion multiply(const Quaternion& q)const;
		void operator *= (const float ts);
		Quaternion operator * (const float ts)const;
		float norm()const;
		Quaternion normalized()const;
		void normalize();
		void convertToUnitNormQuaternion();
		Quaternion conjugate();
		Quaternion inverse();
		void Print();
	};


	}

#endif