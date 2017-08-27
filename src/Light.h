#ifndef LIGHT_H
#define LIGHT_H

#include "math/Vector.h"

class Light
{
public:
	Vector d;

	Light(const Vector& direction) : d{direction} {}
};

#endif // LIGHT_H