#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "../general.h"

#include "Matrix4x4.h"
#include "Point.h"
#include "Vector.h"

class Transform
{
	Matrix4x4 m;
public:
	Transform() : m{Matrix4x4()} {}
	Transform(Matrix4x4 m) : m{m} {}

	inline 			Point		operator()(const Point&);
	inline const 	Point		operator()(const Point&) const;
	inline			Vector		operator()(const Vector&);
	const inline 	Vector		operator()(const Vector&) const;
					Transform	operator* (const Transform& t)			{return {m*t.m};}
	const			Transform	operator* (const Transform& t) const	{return {m*t.m};}
					Transform	operator~ () {return {inv(m)};}

	// Builds a translation transformation
	static Transform T(const Vector&);

	// This is a matrix inversion designed for legit transformation matrices
	static Matrix4x4 inv(const Matrix4x4&);
};



Point Transform::operator()(const Point& p)
{
	return
	{
		p.x*m(0, 0) + p.y*m(1, 0) + p.z*m(2, 0) + m(3, 0),
		p.x*m(0, 1) + p.y*m(1, 1) + p.z*m(2, 1) + m(3, 1),
		p.x*m(0, 2) + p.y*m(1, 2) + p.z*m(2, 2) + m(3, 2)
	};
}

const Point Transform::operator()(const Point& p) const
{
	return
	{
		p.x*m(0, 0) + p.y*m(1, 0) + p.z*m(2, 0) + m(3, 0),
		p.x*m(0, 1) + p.y*m(1, 1) + p.z*m(2, 1) + m(3, 1),
		p.x*m(0, 2) + p.y*m(1, 2) + p.z*m(2, 2) + m(3, 2)
	};
}

Vector Transform::operator()(const Vector& v)
{
	return
	{
		v.x*m(0, 0) + v.y*m(1, 0) + v.z*m(2, 0),
		v.x*m(0, 1) + v.y*m(1, 1) + v.z*m(2, 1),
		v.x*m(0, 2) + v.y*m(1, 2) + v.z*m(2, 2)
	};
}

const Vector Transform::operator()(const Vector& v) const
{
	return
	{
		v.x*m(0, 0) + v.y*m(1, 0) + v.z*m(2, 0),
		v.x*m(0, 1) + v.y*m(1, 1) + v.z*m(2, 1),
		v.x*m(0, 2) + v.y*m(1, 2) + v.z*m(2, 2)
	};
}

#endif // TRANSFORM_H