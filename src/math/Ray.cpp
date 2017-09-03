#include "Ray.h"

Ray::Ray(Transform r2w) : r2w{r2w}
{
	w2r = Transform(Transform::inv(r2w.getM()));
}

Ray::Ray(const Point& o, const Vector& d)
{
	auto pair = Vector::referenceSystem(d);
	Vector& v1 = pair.first;
	Vector& v2 = pair.second;
	
	Matrix4x4 mInv 
	{
		v1.x, v1.y, v1.z, 0,
		v2.x, v2.y, v2.z, 0,
		-d.x, -d.y, -d.z, 0,
		   0,    0,    0, 1
	};

	r2w = Transform(mInv) * Transform::T({o.x, o.y, o.z});
	w2r = Transform(Transform::inv(r2w.getM()));
}

std::pair<Float, Float> RaySpace::origBarCoords(Point p0, Point p1, Point p2)
{
	p1.x -= p0.x; p1.y -= p0.y;
	p2.x -= p0.x; p2.y -= p0.y;
	p0.x = -p0.x; p0.y = -p0.y;
	
	auto det = 1/(p1.x*p2.y - p1.y*p2.x);
	return
	{
		det*(p0.x*p2.y - p0.y*p2.x),
		det*(p1.x*p0.y - p1.y*p0.x)
	};
}

Float RaySpace::getT(Float a, Float b, Point p0, Point p1, Point p2)
{
	return -(a*(p1.z-p0.z)+b*(p2.z-p0.z)+p0.z);
}