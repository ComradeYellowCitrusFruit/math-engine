//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Time for some explanation                                                                            //
// This is a header for more 'simple' math not included within cmath                                    //
// While this may not fit in amongst the far more complex math included within this math engine, I do...//
// ...feel we should include it, in part for convinence sake.                                           //
// With that stated, let's get to the code                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MATH_SIMPLE_FUNCTIONS
#define MATH_SIMPLE_FUNCTIONS
#include <cmath>
#include <src/simple.cpp>
#include "constants.hpp"

// Factorial of int x
int factorial(int x);
// Factorial but as a double, and excepting a varible for step.
double factorialWS(double x, double step) {

// Does the actual math for the golden ratio, if you need some extra precision
long double preciseGoldenRatio();

// Does the actual math for pi with 52 digits of accuracy, which is over kill but if you want 52 digits of accuracy then you can have it.
long double precisePI();
// Does the actual math for pi with 161 digits of accuracy, by all means beyond over kill but you do you I guess.
long double overkillPI();
// Why do I keep adding more versions of Pi?
long double superOverKillPI();
#endif