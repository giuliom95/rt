#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix4x4.h"
#include "Point.h"
#include "Vector.h"

class Transform
{
	Matrix4x4 m, mInv;
public:
	Transform() : m{Matrix4x4::I()}, mInv{Matrix4x4::I()} {}
	Transform(Matrix4x4 m, Matrix4x4 mInv) : m{m}, mInv{mInv} {}
	//If we don't have the inverse matrices we need to compute it here.
	Transform(Matrix4x4 m) : m{m}, mInv{m.inv()} {}

	inline 	Point		operator()(const Point&);
	inline 	Vector		operator()(const Vector&);
			Transform	operator* (const Transform&) {return {m*t.m, t.mInv*mInv};}
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

Vector Transform::operator()(const Vector& v)
{
	return
	{
		v.x*m(0, 0) + v.y*m(1, 0) + v.z*m(2, 0),
		v.x*m(0, 1) + v.y*m(1, 1) + v.z*m(2, 1),
		v.x*m(0, 2) + v.y*m(1, 2) + v.z*m(2, 2)
	};
}

#endif //TRANSFORM_H