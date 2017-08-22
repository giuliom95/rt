#ifndef RAY_H
#define RAY_H

#include <utility>

#include "Transform.h"
#include "Point.h"
#include "Vector.h"

class Ray
{
	Point o;
	Vector d;
	Transform worldToRay;
public:
	Ray(Point, Vector);

	Point operator()(double t) {return o+t*d;}

	/* Computes the parametric coordinates of
	 * the axis origin with respect of the triangle
	 * ignoring the z-values.
	 */
	static std::pair<double, double> origBarCoords(Point, Point, Point);
};


#endif //RAY_H