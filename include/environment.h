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
#include "simple.h"
#include "constants.h"
#include "matrix.h"

struct vector{
    double distance;
    char xyz;
};
class vector2D {
    public:
        vector x;
        vector y;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enter quaternions.                                                                                   //
// Since my days as a (wannabe) game dev, I feared quaternions.                                         //
// They confused me, made my life difficult, made it hell for a young, innocent game dev.               //
// I thought I left them behind, but here I am, once again face to face with quaternions.               //
// May God have mercy on my soul.                                                                       //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class quaternion {
    
};

#endif