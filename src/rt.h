#ifndef RT_H
#define RT_H

#include "Camera.h"
#include "Scene.h"

#include "math/Ray.h"

std::vector<int> render(Camera&, Scene&);

#endif // RT_H