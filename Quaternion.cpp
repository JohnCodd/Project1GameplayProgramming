#include "Quaternion.h"
#include <cmath>

Quaternion::Quaternion()
{
	m_w = 0;
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Quaternion::Quaternion(double w, double x, double y, double z)
{
	m_w = w;
	m_x = x;
	m_y = y;
	m_z = z;
}

Quaternion::Quaternion(double w, Vector3 v)
{
	m_w = w;
	m_x = v.getX();
	m_y = v.getY();
	m_z = v.getZ();
}

std::string Quaternion::ToString()
{
	return "(" + std::to_string(m_w) + "," + std::to_string(m_x) + "i," + std::to_string(m_y) + "j," + std::to_string(m_z) + "k)";
}

double Quaternion::Modulus()
{
	return sqrt(m_w*m_w + m_x*m_x + m_y*m_y + m_z*m_z);
}

Quaternion Quaternion::Normalise()
{
	double m = m_w * m_w + m_x * m_x + m_y * m_y + m_z * m_z;
	if (m > 0.001)
	{
		m = sqrt(m);
		return Quaternion(m_w / m, m_x / m, m_y / m, m_z / m);
	}
	else
	{
		return Quaternion(1, 0, 0, 0);
	}
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(m_w, -m_x, -m_y, -m_z);
}

void Quaternion::FromAxisAngle(Vector3 axis, double angleRadian)
{
	double m = axis.Length();
	if (m > 0.0001)
	{
		double ca = cos(angleRadian / 2);
		double sa = sin(angleRadian / 2);
		m_x = axis.getX() / m * sa;
		m_y = axis.getY() / m * sa;
		m_z = axis.getZ() / m * sa;
	}
	else
	{
		m_w = 1;
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
}

Quaternion Quaternion::Multiply(Quaternion q)
{
	double nw = q.m_w *  m_w - q.m_x *  m_x - q.m_y *  m_y - q.m_z *  m_z;
	double nx = q.m_w *  m_x + q.m_x *  m_w + q.m_y *  m_z - q.m_z *  m_y;
	double ny = q.m_w *  m_y + q.m_y *  m_w + q.m_z *  m_x - q.m_x *  m_z;
	double nz = q.m_w *  m_z + q.m_z *  m_w + q.m_x *  m_y - q.m_y *  m_x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::Copy()
{
	return Quaternion(m_x, m_y, m_z, m_w);
}

Vector3 Quaternion::Rotate(Vector3 pt, int angle)
{
	Quaternion axis, rotate;
	axis = Normalise();
	double angleRad = acos(-1) / 180 * angle;
	rotate = Quaternion(cos(angleRad / 2), sin(angleRad / 2) * axis.m_x, sin(angleRad / 2) * axis.m_y, sin(angleRad / 2) * axis.m_z);
	Quaternion conjugate = rotate.Conjugate();
	Quaternion qNode = Quaternion(0, pt.getX, pt.getY, pt.getZ);
	qNode = rotate * qNode * conjugate;
	return Vector3(qNode.m_x, qNode.m_y, qNode.m_z);
}

Quaternion operator+(Quaternion q1, const Quaternion& q2)
{
	return Quaternion(q1.m_w + q2.m_w, q1.m_x + q2.m_x, q1.m_y + q2.m_y, q1.m_z + q2.m_z);
}

Quaternion operator-(Quaternion q)
{
	return Quaternion(-q.m_w, -q.m_x, -q.m_y, -q.m_z);
}

Quaternion operator-(Quaternion q1, const Quaternion& q2)
{
	return Quaternion(q1.m_w - q2.m_w, q1.m_x - q2.m_x, q1.m_y - q2.m_y, q1.m_z - q2.m_z);
}

Quaternion operator*(Quaternion q, const double& s)
{
	return Quaternion(q.m_w * s, q.m_x * s, q.m_y * s, q.m_z * s);
}

Quaternion operator*(Quaternion q, const float& s)
{
	return Quaternion(q.m_w * s, q.m_x * s, q.m_y * s, q.m_z * s);
}

Quaternion operator*(Quaternion q, const int& s)
{
	return Quaternion(q.m_w * s, q.m_x * s, q.m_y * s, q.m_z * s);
}

Quaternion operator*(double s, const Quaternion& q)
{
	return Quaternion(q.m_w * s, q.m_x * s, q.m_y * s, q.m_z * s);
}

Quaternion operator*(float s, const Quaternion& q)
{
	return Quaternion(q.m_w * s, q.m_x * s, q.m_y * s, q.m_z * s);
}

Quaternion operator*(int s, const Quaternion& q)
{
	return Quaternion(q.m_w * s, q.m_x * s, q.m_y * s, q.m_z * s);
}

Quaternion operator*(Quaternion q1, const Quaternion& q2)
{
	double nw = q1.m_w * q2.m_w - q1.m_x * q2.m_x - q1.m_y * q2.m_y - q1.m_z * q2.m_z;
	double nx = q1.m_w * q2.m_x + q1.m_x * q2.m_w + q1.m_y * q2.m_z - q1.m_z * q2.m_y;
	double ny = q1.m_w * q2.m_y + q1.m_y * q2.m_w + q1.m_z * q2.m_x - q1.m_x * q2.m_z;
	double nz = q1.m_w * q2.m_z + q1.m_z * q2.m_w + q1.m_x * q2.m_y - q1.m_y * q2.m_x;
	return Quaternion(nw, nx, ny, nz);
}