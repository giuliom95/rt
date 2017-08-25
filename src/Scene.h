#ifndef SCENE_H
#define SCENE_H
#include "./general.h"

#include "./math/Point.h"
#include "./math/Transform.h"
#include "./math/Ray.h"

class Scene {
	std::vector<Point> vertices;
	int trisNum;
	int vertsNum;

	Transform lastInv;

	void transformWorld(const Transform&);
public:
	// Loads an obj file
	Scene(std::string);

	int intersect(const Ray&);
};

#endif