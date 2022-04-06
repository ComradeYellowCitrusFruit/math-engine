#ifndef MATH_MISCELLANEOUS_FUNCTIONS
#define MATH_MISCELLANEOUS_FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a file for miscellaneous functions with many uses.											//
// These functions are not 'simple' and are likely faster versions of simpler implementations of...     //
// ...various functions.																				//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cstdint>
#include <src/misc.cpp>

// A double version of fast inverse square root from Quake III: Arena. Source code from https://stackoverflow.com/questions/11644441/fast-inverse-square-root-on-x64
double Q_rsqrt(double number);

#endif