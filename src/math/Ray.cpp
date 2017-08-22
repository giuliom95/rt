#include "Ray.h"

Ray::Ray(Point origin, Vector direction)
{
	o = origin;
	d = direction;
	worldToRay = {};
}

std::pair<double, double> Ray::origBarCoords(Point p1, Point p2, Point p3)
{
	p2.x -= p1.x; p2.y -= p1.y; p2.z -= p1.z;
	p3.x -= p1.x; p3.y -= p1.y; p3.z -= p1.z;
	p1.x = -p1.x; p1.z = -p1.z; p1.z = -p1.z;
	
	auto det = 1/(p2.x*p3.y - p2.y*p3.x);
	return
	{
		det*(p1.x*p3.y - p1.y*p3.x),
		det*(p2.x*p1.y - p2.y*p1.x)
	};
}