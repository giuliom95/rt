#ifndef CAMERA_H
#define CAMERA_H
#include "./general.h"

#include "./math/Point.h"
#include "./math/Vector.h"
#include "./math/Transform.h"
#include "./math/Ray.h"

class Camera
{
	Point p;
	Vector v;
	const double fov;
	const unsigned resX, resY;
	
	Transform c2w;
	Point ulFilm, lrFilm;
public:
	Camera(Point, Vector, double, unsigned, unsigned);

	Ray generateRay(unsigned, unsigned);
};

#endif // CAMERA_H