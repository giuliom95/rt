#ifndef CAMERA_H
#define CAMERA_H

#include "./rt.h"

#include "./math/Point.h"
#include "./math/Vector.h"
#include "./math/Transform.h"
#include "./math/Ray.h"

class Camera
{
	Point p;
	Vector v;
	Transform c2w;
	double fov;

	double csHeight;
public:
	Camera(Point, Vector, double);

	Ray generateRay(unsigned, unsigned);
};

#endif // CAMERA_H