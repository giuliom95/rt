#ifndef POINT_H
#define POINT_H

#include "../rt.h"

#include "Vector.h"

class Point
{
public:
	double x, y, z;

	Point() : x{0}, y{0}, z{0} {}
	Point(double x, double y, double z) : x{x}, y{y}, z{z} {}

	inline			double& operator[](unsigned);
	inline const	double& operator[](unsigned) const;

	Vector	operator- (const Point& p) {return {x-p.x, y-p.y, z-p.z};}

	Point	operator+ (const Vector& v) {return {x+v.x, y+v.y, z+v.z};}
	Point	operator- (const Vector& v) {return (*this)+(-v);}
};

const double& Point::operator[](unsigned idx) const
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

double& Point::operator[](unsigned idx)
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

#endif //POINT_H