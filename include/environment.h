//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  I suppose I owe an explanation as to what this.                                                     //
//  This is a header for all of the math relating to positions, and space.                              //
//  Hence the name, environment.                                                                        //
//  However, since matices have many, many other applications, they are their own catagory.             //
//  Things like quaterninons, positions, vectors, etc. are centered around space, therefore undeserv... //
//  ...ing of their own catagory.                                                                       //
//  Anyway, let's get to the code.                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MATH_ENVIRONMENT
#define MATH_ENVIRONMENT
#include <cmath>
#include "matrix.h"
#include "constants.h"

struct vector{
    double distance;
    char xyz;
};
class vector2D {
    public:
        vector x;
        vector y;
};

// TODO: Take a step into the deepest, darkest, pit of Hell, reserved only for Hitler, Stalin, Mao, Tojo, that one Cambodian asshoole, Satan, and the Anti-Christ (Implement quaternions)



#endif