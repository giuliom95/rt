#ifndef RAY_H
#define RAY_H
#include "../general.h"

#include "Transform.h"
#include "Point.h"
#include "Vector.h"

class Ray
{
public:
	Transform w2r, r2w;

	Ray(Transform r2w);
	Ray(const Point&, const Vector&);

	Point operator()(Float t) 			{return r2w(Point(0,0,-t));}
	Point operator()(Float t) const 	{return r2w(Point(0,0,-t));}
};

// This class contains the operations useful in ray space
class RaySpace
{
public:
	/* The parametric coordinates of the axis origin 
	 * with respect of the triangle ignoring the z-values.
	 */
	static std::pair<Float, Float> origBarCoords(Point, Point, Point);

	// The ray parameter of the intersection
	static Float getT(Float, Float, Point, Point, Point);
};

#endif //RAY_H