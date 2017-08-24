#ifndef CAMERA_H
#define CAMERA_H

#include "./math/Point.h"
#include "./math/Vector.h"

class Camera
{
	Point p;
	Vector v;
	Transform c2w;
public:
	Camera(Point, Vector);
};

#endif // CAMERA_H