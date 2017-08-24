#ifndef SCENE_H
#define SCENE_H
#include "./general.h"

#include "./math/Point.h"

class Scene {
	std::vector<Point> vertices;
public:
	// Loads an obj file
	Scene(std::string);

	void transformWorld(const Transform&);
};

#endif