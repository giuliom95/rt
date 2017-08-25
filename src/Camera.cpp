#include "Camera.h"

Camera::Camera(Point p, Vector look, Vector up, double csh, unsigned filmRes) : res{filmRes}
{
	Vector left = Vector::cross(up, look);

	Matrix4x4 mInv 
	{
		-left.x, -left.y, -left.z, 0,
		   up.x,    up.y,    up.z, 0,
		-look.x, -look.y, -look.z, 0,
		      0,       0,       0, 1
	};

	c2w = Transform(mInv) * Transform::T({p.x, p.y, p.z});
	
	ulFilm = {-csh, +csh, -1};
	lrFilm = {+csh, -csh, -1};
}

Ray Camera::generateRay(unsigned x, unsigned y)
{
	Point p {
		ulFilm.x + ((float)(x)/res)*(lrFilm.x-ulFilm.x),
		ulFilm.y + ((float)(y)/res)*(lrFilm.y-ulFilm.y),
		-1
	};
	Vector v = {0, 0, p.z};

	return {c2w(p), c2w(v)};
}