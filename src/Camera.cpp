#include "Camera.h"

Camera::Camera(Point p, Vector look, Vector up, Float fov, unsigned filmRes) : res{filmRes}
{
	Vector right = Vector::cross(look, up);

	Matrix4x4 mInv 
	{
		right.x, right.y, right.z, 0,
		   up.x,    up.y,    up.z, 0,
		-look.x, -look.y, -look.z, 0,
		      0,       0,       0, 1
	};

	c2w = Transform(mInv) * Transform::T({p.x, p.y, p.z});

	Float csh = std::tan(fov*PI/360);
	ulFilm = {-csh, +csh, -1};
	lrFilm = {+csh, -csh, -1};
}

Ray Camera::generateRay(unsigned x, unsigned y)
{
	Point o = 
	{
		ulFilm.x + ((float)(x)/res)*(lrFilm.x-ulFilm.x),
		ulFilm.y + ((float)(y)/res)*(lrFilm.y-ulFilm.y),
		-1
	};

	Vector d = o - Point();

	return {c2w(o), Vector::normalize(c2w(d))};
}