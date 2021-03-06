#ifndef GENERAL_H
#define GENERAL_H

#include <utility>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


typedef double Float;

static constexpr Float PI = 3.14159265358979323846;
static constexpr Float Infinity = std::numeric_limits<Float>::infinity();
static constexpr Float MachineEpsilon = std::numeric_limits<Float>::epsilon() * 0.5;

inline constexpr Float gamma(int n) {
	return (n * MachineEpsilon) / (1 - n * MachineEpsilon);
}


#endif // GENERAL_H