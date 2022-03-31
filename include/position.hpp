//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  I suppose I owe an explanation as to what this.                                                     //
//  This is a header for all of the math relating to positions.                                         //
//  Hence the name, positions.                                                                          //
//  However, since matices have many, many other applications, they are their own catagory.             //
//  Things like quaterninons, positions, vectors, etc. are centered around space, therefore undeserv... //
//  ...ing of their own catagory.                                                                       //
//  Anyway, let's get to the code.                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MATH_POSITIONAL
#define MATH_POSITIONAL
#include <cmath>
#include "simple.hpp"
#include "constants.hpp"
#include "matrix.hpp"

class vector2D {
    public:
        double x;
        double y;
        double length();
};
class vector3D {
    public:
        double x;
        double y;
        double z;
        double length();
};
class vector4D {
    public:
        double w;
        double x;
        double y;
        double z;
        double length();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enter quaternions.                                                                                   //
// Since my days as a (wannabe) game dev, I feared quaternions.                                         //
// They confused me, made my life difficult, made it hell for a young, innocent game dev.               //
// I thought I left them behind, but here I am, once again face to face with quaternions.               //
// May God have mercy on my soul.                                                                       //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class quaternion {
    public:
        vector4D qw;
        vector3D q;
        double w;
        bool onSphere();
        void returnToSphere();
        quaternion &conjugate();
    private:
        double norm;
        double computeNorm();
};

#endif