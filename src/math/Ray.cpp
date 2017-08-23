#include "Ray.h"

Ray::Ray(Point origin, Vector direction)
{
	o = origin;
	d = direction;

	Transform translation = Transform::T({-o.x, -o.y, -o.z});

	Vector v1, v2;
	if (std::abs(d.x) > std::abs(d.y))
		v1 = (1 / std::sqrt(d.x*d.x + d.z*d.z)) * Vector(-d.z, 0, d.x);
	else
		v1 = (1 / std::sqrt(d.y*d.y + d.z*d.z)) * Vector(0, d.z, -d.y);
	v2 = Vector::cross(d, v1);

	Matrix4x4 mInv 
	{
		v1.x, v1.y, v1.z, 0,
		v2.x, v2.y, v2.z, 0,
		-d.x, -d.y, -d.z, 0,
		   0,    0,    0, 1
	};
	Transform axisChange {Transform::inv(mInv), mInv};

	worldToRay = translation*axisChange;
}


std::pair<double, double> RaySpace::origBarCoords(Point p1, Point p2, Point p3)
{
	p2.x -= p1.x; p2.y -= p1.y;
	p3.x -= p1.x; p3.y -= p1.y;
	p1.x = -p1.x; p1.y = -p1.y;
	
	auto det = 1/(p2.x*p3.y - p2.y*p3.x);
	return
	{
		det*(p1.x*p3.y - p1.y*p3.x),
		det*(p2.x*p1.y - p2.y*p1.x)
	};
}

double RaySpace::getT(double a, double b, Point p1, Point p2, Point p3)
{
	return -(a*(p2.z-p1.z)+b*(p3.z-p1.z)+p1.z);
}