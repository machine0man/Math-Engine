#include "Vectors.h"
#include "Matrix.h"

namespace machineman
{
#pragma region Constructors

	Matrix3n::Matrix3n()
	{
		for (int i = 0; i < 9; i++)matrix[i] = 0.0f;
		matrix[0] = matrix[4] = matrix[8] = 1.0f;
	}
	Matrix3n::Matrix3n(float e0, float e3, float e6, float e1, float e4, float e7, float e2, float e5, float e8)
	{
		matrix[0] = e0; matrix[1] = e1; matrix[2] = e2;
		matrix[3] = e3; matrix[4] = e4; matrix[5] = e5;
		matrix[6] = e6; matrix[7] = e7; matrix[8] = e8;
		// 3x3 matrix - column major. X vector is 0, 1, 2, etc. (openGL prefer way)
		//    0    3    6
		//    1    4    7
		//    2    5    8

		//Example 
		//2*2 Column Major Matrix        // 2*2 Row Major Matrix
		// a[0][0] a[1][0]				 //a[0][0] a[0][1]
		// a[0][1] a[1][1]				 //a[1][0] a[1][1]

	}
	Matrix3n& Matrix3n::operator = (const Matrix3n& mat)
	{
		for (int i = 0;i < 9;i++)
			matrix[i] = mat.matrix[i];

		return *this;
	}
#pragma endregion

#pragma region Destructors

	Matrix3n::~Matrix3n() {}

#pragma endregion

#pragma region Addition

	Matrix3n Matrix3n::operator + (const Matrix3n& mat)const
	{
		return Matrix3n( // Column Major Matrix
			matrix[0] + mat.matrix[0],
			matrix[3] + mat.matrix[3],
			matrix[6] + mat.matrix[6],
			matrix[1] + mat.matrix[1],
			matrix[4] + mat.matrix[4],
			matrix[7] + mat.matrix[7],
			matrix[2] + mat.matrix[2],
			matrix[5] + mat.matrix[5],
			matrix[8] + mat.matrix[8]
		);
	}

	void Matrix3n::operator += (const Matrix3n& mat)
	{
		for (int i = 0;i < 9;i++) matrix[i] += mat.matrix[i];
		

	}

#pragma endregion

#pragma region Subtraction
	Matrix3n Matrix3n::operator - (const Matrix3n& mat)const
	{
		Matrix3n tmat;

		for (int i = 0; i < 9; i++)
			tmat.matrix[i] = matrix[i] - mat.matrix[i];

		return tmat;

	}

	void Matrix3n::operator -= (const Matrix3n& mat)
	{
		for (int i = 0;i < 9;i++) matrix[i] -= mat.matrix[i];
	}

#pragma endregion

#pragma region Scalar Multiplication
	Matrix3n Matrix3n::operator * (const float n)const
	{
		Matrix3n tmat;
		for (int i = 0;i < 9;i++) tmat.matrix[i] = matrix[i] * n;
		return tmat;
	}
	void Matrix3n::operator *= (const float n)
	{
		for (int i = 0;i < 9;i++) matrix[i] *= n;
	}

#pragma endregion

#pragma region Matrix Multiplication
	Matrix3n Matrix3n::operator * (const Matrix3n& mat)const
	{
		return Matrix3n
		{
			matrix[0] * mat.matrix[0] + matrix[3] * mat.matrix[1] + matrix[6] * mat.matrix[2],//0
			matrix[0] * mat.matrix[3] + matrix[3] * mat.matrix[4] + matrix[6] * mat.matrix[5],//3
			matrix[0] * mat.matrix[6] + matrix[3] * mat.matrix[7] + matrix[6] * mat.matrix[8],//6

			matrix[1] * mat.matrix[0] + matrix[4] * mat.matrix[1] + matrix[7] * mat.matrix[2],//1
			matrix[1] * mat.matrix[3] + matrix[4] * mat.matrix[4] + matrix[7] * mat.matrix[5],//4
			matrix[1] * mat.matrix[6] + matrix[4] * mat.matrix[7] + matrix[7] * mat.matrix[8],//7

			matrix[2] * mat.matrix[0] + matrix[5] * mat.matrix[1] + matrix[8] * mat.matrix[2],//2
			matrix[2] * mat.matrix[3] + matrix[5] * mat.matrix[4] + matrix[8] * mat.matrix[5],//5
			matrix[2] * mat.matrix[6] + matrix[5] * mat.matrix[7] + matrix[8] * mat.matrix[8],//8
		};
	}
	void Matrix3n::operator *= (const Matrix3n& mat)
	{
		float t1, t2, t3;

		t1 = matrix[0] * mat.matrix[0] + matrix[3] * mat.matrix[1] + matrix[6] * mat.matrix[2];//0
		t2 = matrix[0] * mat.matrix[3] + matrix[3] * mat.matrix[4] + matrix[6] * mat.matrix[5];//3
		t3 = matrix[0] * mat.matrix[6] + matrix[3] * mat.matrix[7] + matrix[6] * mat.matrix[8];//6
		matrix[0] = t1;
		matrix[3] = t2;
		matrix[6] = t3;
		t1 = matrix[1] * mat.matrix[0] + matrix[4] * mat.matrix[1] + matrix[7] * mat.matrix[2];//1
		t2 = matrix[1] * mat.matrix[3] + matrix[4] * mat.matrix[4] + matrix[7] * mat.matrix[5];//4
		t3 = matrix[1] * mat.matrix[6] + matrix[4] * mat.matrix[7] + matrix[7] * mat.matrix[8];//7
		matrix[1] = t1;
		matrix[4] = t2;
		matrix[7] = t3;
		t1 = matrix[2] * mat.matrix[0] + matrix[5] * mat.matrix[1] + matrix[8] * mat.matrix[2];//2
		t2 = matrix[2] * mat.matrix[3] + matrix[5] * mat.matrix[4] + matrix[8] * mat.matrix[5];//5
		t3 = matrix[2] * mat.matrix[6] + matrix[5] * mat.matrix[7] + matrix[8] * mat.matrix[8];//8
		matrix[2] = t1;
		matrix[5] = t2;
		matrix[8] = t3;
	}


#pragma endregion

#pragma region Identity Matrix
	void Matrix3n::setMatrixAsIdentityMatrix()
	{
		for (int i = 0;i < 9;i++) matrix[i] = 0.0f;
		matrix[0] = matrix[4] = matrix[8] = 1.0f;

	}
#pragma endregion

#pragma region Transpose Matrix
	void Matrix3n::setMatrixAsTransposeOfGivenMatrix(const Matrix3n& mat)
	{
		matrix[0] = mat.matrix[0];
		matrix[3] = mat.matrix[1];
		matrix[6] = mat.matrix[2];

		matrix[1] = mat.matrix[3];
		matrix[4] = mat.matrix[4];
		matrix[7] = mat.matrix[5];

		matrix[2] = mat.matrix[6];
		matrix[5] = mat.matrix[7];
		matrix[8] = mat.matrix[8];

	}
	Matrix3n Matrix3n::getTransposeOfMatrix()const
	{
		Matrix3n tmat;
		tmat.setMatrixAsTransposeOfGivenMatrix(*this);
		return tmat;
	}

#pragma endregion

#pragma region Inverse
	void Matrix3n::setMatrixAsInverseOfGivenMatrix(const Matrix3n& mat)
	{
		float det;
		float m00, m01, m02;
		m00 = (mat.matrix[4] * mat.matrix[8] - mat.matrix[5] * mat.matrix[7]);
		m01 = -(mat.matrix[3] * mat.matrix[8] - mat.matrix[5] * mat.matrix[6]);
		m02 = (mat.matrix[3] * mat.matrix[7] - mat.matrix[4] * mat.matrix[6]);

		det = mat.matrix[0] * m00 + mat.matrix[1] * m01 + mat.matrix[2] * m02;
		if (det == 0.0f) return;

		float inv_det = 1.0f / det;
		float m10, m11, m12, m20, m21, m22;
		m10 = -(mat.matrix[1] * mat.matrix[8] - mat.matrix[2] * mat.matrix[7]);
		m11 = (mat.matrix[0] * mat.matrix[8] - mat.matrix[2] * mat.matrix[6]);
		m12 = -(mat.matrix[0] * mat.matrix[7] - mat.matrix[1] * mat.matrix[6]);

		m20 = (mat.matrix[1] * mat.matrix[5] - mat.matrix[2] * mat.matrix[4]);
		m21 = -(mat.matrix[0] * mat.matrix[5] - mat.matrix[2] * mat.matrix[3]);
		m22 = (mat.matrix[0] * mat.matrix[4] - mat.matrix[1] * mat.matrix[3]);

		//Making Transpose here
		matrix[0] = m00 * inv_det;
		matrix[3] = m01 * inv_det;
		matrix[6] = m02 * inv_det;
		matrix[1] = m10 * inv_det;
		matrix[4] = m11 * inv_det;
		matrix[7] = m12 * inv_det;
		matrix[2] = m20 * inv_det;
		matrix[5] = m21 * inv_det;
		matrix[8] = m22 * inv_det;
	}
	Matrix3n Matrix3n::getInverseOfMatrix()const
	{
		Matrix3n tmat;
		tmat.setMatrixAsInverseOfGivenMatrix(*this);
		return tmat;
	}
	void Matrix3n::invertMatrix()
	{
		setMatrixAsInverseOfGivenMatrix(*this);
	}
#pragma endregion 

#pragma region Vector Transformation
	Vector3d Matrix3n::operator * (const Vector3d& v)const
	{
		return Vector3d
		(
			matrix[0] * v.x + matrix[3] * v.y + matrix[6] * v.z,
			matrix[1] * v.x + matrix[4] * v.y + matrix[7] * v.z,
			matrix[2] * v.x + matrix[5] * v.y + matrix[8] * v.z
		);
	}
	Vector3d Matrix3n::transformVectorByMatrix(const Vector3d& v)const
	{
		return (*this) * v;
	}

#pragma endregion 

#pragma region Display
	void Matrix3n::Print()
	{
		std::cout << "{"
			<< matrix[0] << "," << matrix[3] << "," << matrix[6] << "," << std::endl
			<< matrix[1] << "," << matrix[4] << "," << matrix[7] << "," << std::endl
			<< matrix[2] << "," << matrix[5] << "," << matrix[8] << "}" << std::endl;
	}
#pragma endregion





}