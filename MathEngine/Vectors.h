#ifndef Vectors
#define Vectors

#include <iostream>

namespace machineman {

	class Vector3d
	{

	public:
		float x, y, z;

		//Constructors
		Vector3d();
		Vector3d(const Vector3d& v);
		Vector3d& operator = (const Vector3d& v);
		Vector3d(float tx, float ty, float tz);

		//Destructors
		~Vector3d();

		//Methods
		void Print();
		Vector3d operator + (Vector3d const& v)const;   // const can be used before/after "Vector" interchangeably 
	    void operator += (const Vector3d& v);
		Vector3d operator - (Vector3d const& v)const;  
		void operator -= (const Vector3d& v);
		Vector3d operator * (const float n)const ;
		void operator *= (const float n);
		Vector3d operator / (const float n)const;
		void operator /= (const float n);
		float dot (const Vector3d& v)const;
		float operator *(const Vector3d& v)const;
		Vector3d cross(const Vector3d& v)const;
		Vector3d operator %(const Vector3d& v)const;
		float magnitude();
		Vector3d normalized();
		void normalize();
		Vector3d rotateVectorAboutAngleAndAxis(float Angle, Vector3d& Axis);
		
	};



}

#endif