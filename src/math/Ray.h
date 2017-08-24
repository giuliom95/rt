#ifndef RAY_H
#define RAY_H

#include "../rt.h"

#include "Transform.h"
#include "Point.h"
#include "Vector.h"

class Ray
{
public:
	Point o;
	Vector d;
	Transform w2r, r2w;

	Ray(Point, Vector);

	Point operator()(double t) {return o+t*d;}
};

// This class contains the operations useful in ray space
class RaySpace
{
public:
	/* The parametric coordinates of the axis origin 
	 * with respect of the triangle ignoring the z-values.
	 */
	static std::pair<double, double> origBarCoords(Point, Point, Point);

	// The ray parameter of the intersection
	static double getT(double, double, Point, Point, Point);
};

#endif //RAY_H