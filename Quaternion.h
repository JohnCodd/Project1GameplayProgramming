#pragma once
#include "Vector3.h"
#include <string>

class Quaternion
{
	friend Quaternion operator+(Quaternion, const Quaternion&);
	friend Quaternion operator-(Quaternion);
	friend Quaternion operator-(Quaternion, const Quaternion&);
	friend Quaternion operator*(Quaternion, const double&);
	friend Quaternion operator*(Quaternion, const float&);
	friend Quaternion operator*(Quaternion, const int&);
	friend Quaternion operator*(double, const Quaternion&);
	friend Quaternion operator*(float, const Quaternion&);
	friend Quaternion operator*(int, const Quaternion&);
	friend Quaternion operator*(Quaternion, const Quaternion&);
public:
	Quaternion();
	Quaternion(double w, double x, double y, double z);
	Quaternion(double w, Vector3 v);
	std::string ToString();
	double Modulus();
	Quaternion Normalise();
	Quaternion Conjugate();
	void FromAxisAngle(Vector3 axis, double andgleRadian);
	Quaternion Multiply(Quaternion q);
	Quaternion Copy();
	Vector3 Rotate(Vector3 pt, int angle);
private:
	double m_x, m_y, m_z, m_w;
};