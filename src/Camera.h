#ifndef CAMERA_H
#define CAMERA_H
#include "./general.h"

#include "./math/Point.h"
#include "./math/Vector.h"
#include "./math/Transform.h"
#include "./math/Ray.h"

class Camera
{
	const unsigned res;

	Point ulFilm, lrFilm;
	Transform c2w; // Camera to World transformation
public:
	Camera(Point, Vector, Vector, Float, unsigned);

	Ray generateRay(unsigned, unsigned);

	unsigned getFilmRes() {return res;}
};

#endif // CAMERA_H