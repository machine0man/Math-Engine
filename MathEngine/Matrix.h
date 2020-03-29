#pragma once
#ifndef Matrix
#define Matrix

#include <iostream>
#include "Vectors.h"

namespace machineman {

	class Matrix3n
	{
	private:
	public:
		float matrix[9] = {0.0f};

	
		//Constructors
		Matrix3n();
		Matrix3n(float e0, float e3, float e6, float e1, float e4, float e7, float e2, float e5, float e8 );
		Matrix3n& operator = (const Matrix3n& mat);

		//Methods
		Matrix3n operator + (const Matrix3n& mat)const;
		void operator += (const Matrix3n& mat);
		Matrix3n operator - (const Matrix3n& mat)const;
		void operator -= (const Matrix3n& mat);
		Matrix3n operator * (const float n )const;
		void operator *= (const float n);
		Matrix3n operator * (const Matrix3n& mat)const;
		void operator *= (const Matrix3n& mat);
		void setMatrixAsIdentityMatrix();
		void setMatrixAsTransposeOfGivenMatrix(const Matrix3n& mat);
		Matrix3n getTransposeOfMatrix()const;
		void setMatrixAsInverseOfGivenMatrix(const Matrix3n& mat);
		Matrix3n getInverseOfMatrix()const;
		void invertMatrix();
		Vector3d operator * (const Vector3d& v)const;
		Vector3d transformVectorByMatrix(const Vector3d& v)const;

		~Matrix3n();
		void Print();

	};



}

#endif