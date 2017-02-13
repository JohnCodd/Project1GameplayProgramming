#pragma once
#include "Vector3.h"

class Matrix3
{
	friend Vector3 operator*(Matrix3, Vector3);
	friend Vector3 operator*(Vector3, Matrix3);
	friend Matrix3 operator+(Matrix3, Matrix3);
	friend Matrix3 operator-(Matrix3, Matrix3);
	friend Matrix3 operator*(double, Matrix3);
	friend Matrix3 operator*(Matrix3, Matrix3);
	friend Matrix3 operator-(Matrix3);
public:
	Matrix3();
	Matrix3(Vector3, Vector3, Vector3);
	Matrix3(double, double, double, double, double, double, double, double, double);
	Matrix3 Transpose(Matrix3);
	double Determinant(Matrix3);
	Vector3 Row(int);
	Vector3 Column(int);
	Matrix3 Inverse(Matrix3);
	Matrix3 Rotation(int);
	Matrix3 Translate(int, int);
	Matrix3 Scale(int, int);
	Matrix3 RotationX(int);
	Matrix3 RotationY(int);
	Matrix3 RotationZ(int);
	Matrix3 Scale3D(int);
private:
	double A11, A12, A13, A21, A22, A23, A31, A32, A33;
};