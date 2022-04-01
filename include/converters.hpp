#ifndef MATH_CONVERTERS
#define MATH_CONVERTERS
#include <cmath>
#include <src/converters.cpp>
#include "constants.hpp"

double angleConverter(double x, char RorD);
double temperature(double x, char type, char to);
double distance(double x, char type, char to);

#endif