#include "Vector.h"

std::pair<Vector, Vector> Vector::referenceSystem(const Vector& v)
{
	Vector v1, v2;
	if (std::abs(v.x) > std::abs(v.y))
		v1 = (1 / std::sqrt(v.x*v.x + v.z*v.z)) * Vector(-v.z, 0, v.x);
	else
		v1 = (1 / std::sqrt(v.y*v.y + v.z*v.z)) * Vector(0, v.z, -v.y);
	v2 = cross(v, v1);
	return {v1, v2};
}