#include "Ray.h"

Ray::Ray(Transform r2w) : r2w{r2w}
{
	w2r = Transform(Transform::inv(r2w.getM()));
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