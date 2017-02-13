#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
	m_x = 0.0f;
	m_y = 0.0f;
	m_z = 0.0f;
}

Vector3::Vector3(double x, double y, double z)
{ 
	m_x = x;
	m_y = y;
	m_z = z;
}

Vector3::Vector3(const Vector3& o)
{ 
	m_x = o.m_x;
	m_y = o.m_y;
	m_z = o.m_z;
}

Vector3::~Vector3()
{

}

const double Vector3::getX() { return m_x; }

const double Vector3::getY() { return m_y; }

const double Vector3::getZ() { return m_z; }

const Vector3 Vector3::operator-(const Vector3& v) const
{
	return Vector3(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
}

Vector3 operator+(Vector3 v1, const Vector3& v2)
{
	return Vector3(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z);
}

Vector3 operator-(Vector3 v1, const Vector3& v2)
{
	return Vector3(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z);
}

double operator*(Vector3 v1, const Vector3& v2)
{
	return double(v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z);
}

Vector3 operator*(double k, const Vector3& v)
{
	return Vector3(v.m_x * k, v.m_y * k, v.m_z * k);
}

Vector3 operator*(float k, const Vector3& v)
{
	return Vector3(v.m_x * (double)k, v.m_y * (double)k, v.m_z * (double)k);
}

Vector3 operator*(int k, const Vector3& v)
{
	return Vector3(v.m_x * (double)k, v.m_y * (double)k, v.m_z * (double)k);
}

Vector3 operator^(Vector3 v1, const Vector3& v2)
{
	return Vector3(v1.m_y * v2.m_z - v1.m_z * v2.m_y, v1.m_z * v2.m_x - v1.m_x * v2.m_z, v1.m_x * v2.m_y - v1.m_y * v2.m_x);
}

double Vector3::Length()
{
	return (double)std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Vector3::LengthSq()
{
	return (m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vector3::Normalise()
{
	if (Length() > 0.0)
	{
		double magnit = Length();
		m_x /= magnit;
		m_y /= magnit;
		m_z /= magnit;
	}
}