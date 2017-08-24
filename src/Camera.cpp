#include "Camera.h"

Ray::Ray(Point position, Vector lookAt) : p{position}, v{lookAt}
{
	auto pair = Vector::referenceSystem(v);
	Vector v1 = pair.first;
	Vector v2 = pair.second;

	Matrix4x4 mInv 
	{
		v1.x, v1.y, v1.z, 0,
		v2.x, v2.y, v2.z, 0,
		-v.x, -v.y, -v.z, 0,
		   0,    0,    0, 1
	};

	c2w = Transform(mInv) * Transform::T({p.x, p.y, p.z});
}