#ifndef POINT_H
#define POINT_H
#include "../general.h"

#include "Vector.h"

class Point
{
public:
	Float x, y, z;

	Point() : x{0}, y{0}, z{0} {}
	Point(Float x, Float y, Float z) : x{x}, y{y}, z{z} {}

	inline			Float& operator[](unsigned);
	inline const	Float& operator[](unsigned) const;

	Vector	operator- (const Point& p) {return {x-p.x, y-p.y, z-p.z};}

	Point	operator+ (const Vector& v) {return {x+v.x, y+v.y, z+v.z};}
	Point	operator- (const Vector& v) {return (*this)+(-v);}
};

const Float& Point::operator[](unsigned idx) const
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

Float& Point::operator[](unsigned idx)
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

#endif //POINT_H