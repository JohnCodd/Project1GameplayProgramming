#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3()
{
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)
{
	A11 = Row1.getX();
	A12 = Row1.getY();
	A13 = Row1.getZ();
	A21 = Row2.getX();
	A22 = Row2.getY();
	A23 = Row2.getZ();
	A31 = Row3.getX();
	A32 = Row3.getY();
	A33 = Row3.getZ();
}

Matrix3::Matrix3(double _A11, double _A12, double _A13, double _A21,
	double _A22, double _A23, double _A31, double _A32, double _A33)
{
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

Vector3 operator*(Matrix3 M1, Vector3 V1)
{
	return Vector3(M1.Row(1).getX * V1.getX + M1.Row(1).getY * V1.getY + M1.Row(1).getZ * V1.getZ,
		M1.Row(2).getX * V1.getX + M1.Row(2).getY * V1.getY + M1.Row(2).getZ * V1.getZ,
		M1.Row(3).getX * V1.getX + M1.Row(3).getY * V1.getY + M1.Row(3).getZ * V1.getZ);
}

Vector3 operator*(Vector3 V1, Matrix3 M1)
{
	return Vector3(M1.Row(1).getX * V1.getX + M1.Row(1).getY * V1.getY + M1.Row(1).getZ * V1.getZ,
		M1.Row(2).getX * V1.getX + M1.Row(2).getY * V1.getY + M1.Row(2).getZ * V1.getZ,
		M1.Row(3).getX * V1.getX + M1.Row(3).getY * V1.getY + M1.Row(3).getZ * V1.getZ);
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{
	return Matrix3(M1.Row(1).getX, M1.Row(2).getX, M1.Row(3).getX,
		M1.Row(1).getY, M1.Row(2).getY, M1.Row(3).getY,
		M1.Row(1).getZ, M1.Row(2).getZ, M1.Row(3).getZ);
}

Matrix3 operator+(Matrix3 M1, Matrix3 M2)
{
	return Matrix3(M1.Row(1).getX + M2.Row(1).getX, M1.Row(1).getY + M2.Row(1).getY, M1.Row(1).getZ + M2.Row(1).getZ,
		M1.Row(2).getX + M2.Row(2).getX, M1.Row(2).getY + M2.Row(2).getY, M1.Row(2).getZ + M2.Row(2).getZ,
		M1.Row(3).getX + M2.Row(3).getX, M1.Row(3).getY + M2.Row(3).getY, M1.Row(3).getZ + M2.Row(3).getZ);
}

Matrix3 operator-(Matrix3 M1, Matrix3 M2)
{
	return Matrix3(M1.Row(1).getX - M2.Row(1).getX, M1.Row(1).getY - M2.Row(1).getY, M1.Row(1).getZ - M2.Row(1).getZ,
		M1.Row(2).getX - M2.Row(2).getX, M1.Row(2).getY - M2.Row(2).getY, M1.Row(2).getZ - M2.Row(2).getZ,
		M1.Row(3).getX - M2.Row(3).getX, M1.Row(3).getY - M2.Row(3).getY, M1.Row(3).getZ - M2.Row(3).getZ);
}

Matrix3 operator*(double x, Matrix3 M1)
{
	Vector3 Row1 = Vector3(M1.Row(1).getX * x, M1.Row(1).getY * x, M1.Row(1).getZ * x);
	Vector3 Row2 = Vector3(M1.Row(2).getX * x, M1.Row(2).getY * x, M1.Row(2).getZ * x);
	Vector3 Row3 = Vector3(M1.Row(3).getX * x, M1.Row(3).getY * x, M1.Row(3).getZ * x);
	return Matrix3(Row1, Row2, Row3);
}

Matrix3 operator*(Matrix3 M1, Matrix3 M2)
{
	Vector3 Row1 = Vector3(M1.Row(1) * M2.Column(1), M1.Row(1) * M2.Column(2), M1.Row(1) * M2.Column(3));
	Vector3 Row2 = Vector3(M1.Row(2) * M2.Column(1), M1.Row(2) * M2.Column(2), M1.Row(2) * M2.Column(3));
	Vector3 Row3 = Vector3(M1.Row(3) * M2.Column(1), M1.Row(3) * M2.Column(2), M1.Row(3) * M2.Column(3));
	return Matrix3(Row1, Row2, Row3);
}

double Matrix3::Determinant(Matrix3 M1)
{
	return M1.Row(1).getX * M1.Row(2).getY * M1.Row(3).getZ -
		M1.Row(1).getX * M1.Row(3).getY * M1.Row(2).getZ +
		M1.Row(2).getX * M1.Row(3).getY * M1.Row(1).getZ -
		M1.Row(3).getX * M1.Row(2).getY * M1.Row(1).getZ +
		M1.Row(3).getX * M1.Row(1).getY * M1.Row(2).getZ -
		M1.Row(2).getX * M1.Row(1).getY * M1.Row(3).getZ;
}

Vector3 Matrix3::Row(int i)
{
	switch (i)
	{
	case 1:
		return Vector3(A11, A12, A13);
	case 2:
		return Vector3(A21, A22, A23);
	case 3:
		return Vector3(A31, A32, A33);
	}

}Vector3 Matrix3::Column(int i)
{
	switch (i)
	{
	case 1:
		return Vector3(A11, A21, A31);
	case 2:
		return Vector3(A12, A22, A32);
	case 3:
		return Vector3(A13, A23, A33);
	}
}

Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	double det = Determinant(M1);
	if (det == 0)
		return Matrix3();
	else
	{
		double scale = 1 / det;
		Vector3 Row1 = Vector3(
			scale * (M1.Row(2).getY * M1.Row(3).getZ - M1.Row(2).getZ * M1.Row(3).getY),
			scale * (M1.Row(1).getZ * M1.Row(3).getY - M1.Row(1).getY * M1.Row(3).getZ),
			scale * (M1.Row(1).getY * M1.Row(2).getZ - M1.Row(1).getZ * M1.Row(2).getY));
		Vector3 Row2 = Vector3(
			scale * (M1.Row(2).getZ * M1.Row(3).getX - M1.Row(2).getX * M1.Row(3).getZ),
			scale * (M1.Row(1).getX * M1.Row(3).getZ - M1.Row(1).getZ * M1.Row(3).getX),
			scale * (M1.Row(1).getZ * M1.Row(2).getX - M1.Row(1).getX * M1.Row(2).getZ));
		Vector3 Row3 = Vector3(
			scale * (M1.Row(2).getX * M1.Row(3).getX - M1.Row(2).getY * M1.Row(3).getX),
			scale * (M1.Row(1).getY * M1.Row(3).getX - M1.Row(1).getX * M1.Row(3).getY),
			scale * (M1.Row(1).getX * M1.Row(2).getX - M1.Row(1).getY * M1.Row(2).getX));
		return Matrix3(Row1, Row2, Row3);
	}
}

Matrix3 Matrix3::Rotation(int angle)
{
	double radians = acos(-1) / 180 * angle;
	Vector3 Row1 = Vector3(cos(radians), sin(radians), 0);
	Vector3 Row2 = Vector3(-sin(radians), cos(radians), 0);
	Vector3 Row3 = Vector3(0, 0, 1);
	return Matrix3(Row1, Row2, Row3);
}

Matrix3 Matrix3::Translate(int dx, int dy)
{
	Vector3 Row1 = Vector3(1, 0, 0);
	Vector3 Row2 = Vector3(0, 1, 0);
	Vector3 Row3 = Vector3(dx, dy, 1);
	return Matrix3(Row1, Row2, Row3);
}

Matrix3 Matrix3::Scale(int dx, int dy)
{
	Vector3 Row1 = Vector3((double)dx / 100, 0, 0);
	Vector3 Row2 = Vector3(0, (double)dy / 100, 0);
	Vector3 Row3 = Vector3(0, 0, 1);
	return Matrix3(Row1, Row2, Row3);
}

Matrix3 operator-(Matrix3 M1)
{
	return -1 * M1;
}

Matrix3 Matrix3::RotationX(int angle)
{
	double radians = acos(-1) / 180 * angle;
	Vector3 Row1 = Vector3(1, 0, 0);
	Vector3 Row2 = Vector3(0, cos(radians), -sin(radians));
	Vector3 Row3 = Vector3(0, sin(radians), cos(radians));
	return Matrix3(Row1, Row2, Row3);
}

Matrix3 Matrix3::RotationY(int angle)
{
	double radians = acos(-1) / 180 * angle;
	Vector3 Row1 = Vector3(cos(radians), 0, sin(radians));
	Vector3 Row2 = Vector3(0, 1, 0);
	Vector3 Row3 = Vector3(-sin(radians), 0, cos(radians));
	return Matrix3(Row1, Row2, Row3);
}

Matrix3 Matrix3::RotationZ(int angle)
{
	double radians = acos(-1) / 180 * angle;
	Vector3 Row1 = Vector3(cos(radians), -sin(radians), 0);
	Vector3 Row2 = Vector3(sin(radians), cos(radians), 0);
	Vector3 Row3 = Vector3(0, 0, 1);
}

Matrix3 Matrix3::Scale3D(int dx)
{
	Vector3 Row1 = Vector3((double)dx / 100, 0, 0);
	Vector3 Row2 = Vector3(0, (double)dx / 100, 0);
	Vector3 Row3 = Vector3(0, 0, (double)dx / 100);
	return Matrix3(Row1, Row2, Row3);
}