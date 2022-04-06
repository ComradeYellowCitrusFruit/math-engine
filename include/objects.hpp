//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Ah yes, 3D objects.                                                                                 //
//  The next step into madness.                                                                         //
//  Oh well, since this is just math, not rendering or physics (technically), we should be fine.        //
//  For a little while, at least.                                                                       //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MATH_3D_OBJECTS
#define MATH_3D_OBJECTS
#include <cmath>
#include <thread>
#include <mutex>

#include <src/vectors.cpp>
#include <src/quaternions.cpp>

// Of course positions are involved, this is literally where 3d models are defined
#include "position.hpp"
#include "constants.hpp"
#include "converters.hpp"
#include "matrix.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  So, here we are, vertices, the building blocks of polygons, and therefore 3d models                 //
//  The first circle of our little hell.                                                                //
//  These are basically fancy vectors for our purposes right now.                                       //
//  Triangles will serve to break down polygons as well                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class vertex {
    public:
        vertex(double identifier, double x, double y, double z);
        double x;
        double y;
        double z;
        double getID();
    private:
        double id;
};

class tri {
    public:
        tri(vertex a, vertex b, vertex c, double identifier);
        double x;
        double y;
        double z;
        double getID();
        void setVerts(vertex newVerts);
        vertex getVerts();
        void averagePos();
    private:
        vertex verts[3];
        double id;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Ah yes, models...                                                                                   //
//  Reminds me of blender, good piece of software btw.                                                  //
//  Anyway time for actual code.                                                                        //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class model {
    public:
        model(vertex vertices[], tri triangles[], vector3D pos, double ID);
        vector3D pos;
        std::array<vertex, 3> getVerts();
        void setVerts(vertex newVerts);
        tri getTris();
        void setTris(tri newTris);
    private:
        vertex verts[1];
        tri tris[1];
        double id;
        void updateTris(int threads);
        void thr_updateTris(int min, int max, std::mutex mtx);
};

#endif