#ifndef SCENE_H
#define SCENE_H
#include "./general.h"

#include "./Camera.h"

#include "./math/Point.h"
#include "./math/Transform.h"
#include "./math/Ray.h"

class Scene {
	std::vector<Point> vertices;
	std::vector<Vector> normals;
	int trisNum;
	int vertsNum;

	Transform lastInv;

	void transformWorld(const Transform&);
public:
	// Loads an obj file
	Scene(std::istream&);

	bool intersect(const Ray&, Vector&);
	std::vector<int> render(Camera&);
};

#endif