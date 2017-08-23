#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "./math/Point.h"

class Scene {
	std::vector<Point> vertices;
public:
	// Loads an obj file
	Scene(std::string);
};

#endif