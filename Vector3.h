#pragma once

class Vector3
{
	friend Vector3 operator+(Vector3, const Vector3&);
	friend Vector3 operator-(Vector3, const Vector3&);
	friend double operator*(Vector3, const Vector3&);
	friend Vector3 operator*(double, const Vector3&);
	friend Vector3 operator*(float, const Vector3&);
	friend Vector3 operator*(int, const Vector3&);
	friend Vector3 operator^(Vector3, const Vector3&);
public:
	Vector3();
	Vector3(double, double, double);
	Vector3(const Vector3&);
	~Vector3();
	double Length();
	double LengthSq();
	void Normalise();
	const double getX();
	const double getY();
	const double getZ();
	const Vector3 operator-(const Vector3&) const;
private:
	double m_x, m_y, m_z;
};