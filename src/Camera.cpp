#include "Camera.h"

Camera::Camera(Point position, Vector lookAt, double fov, unsigned filmResX, unsigned filmResY) : 
p{position}, v{lookAt}, fov{fov}, resX{filmResX}, resY{filmResY}
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
	
	// tan of fov/2
	double csh = std::tan(fov*PI/360);
	ulFilm = {-csh, +csh, -1};
	lrFilm = {+csh, -csh, -1};
}

Ray Camera::generateRay(unsigned x, unsigned y)
{
	Point p {
		ulFilm.x + ((float)(x)/resX)*(lrFilm.x-ulFilm.x),
		ulFilm.y + ((float)(y)/resY)*(lrFilm.y-ulFilm.y),
		-1
	};
	Vector v = {0, 0, p.z};

	return {c2w(p), c2w(v)};
}