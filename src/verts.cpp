//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  So, here we are, vertices, the building blocks of polygons, and therefore 3d models                 //
//  The first circle of our little hell.                                                                //
//  These are basically fancy vectors for our purposes right now.                                       //
//  Triangles will serve to break down polygons as well                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <thread>
#include <array>
#include "position.hpp"
#include "constants.hpp"
#include "converters.hpp"
#include "matrix.hpp"
#include "objects.hpp"

class vertex {
    public:
        vertex(double identifier, double X, double Y, double Z) {
            id = identifier;
            x = X;
            y = Y;
            z = Z;
        }
        vertex() {
            id = 0;
            x = 0;
            y = 0;
            z = 0;
        }
        double x;
        double y;
        double z;
        double getID() {
            return(id);
        }
    private:
        double id;
};

class tri {
    public:
        tri(vertex a, vertex b, vertex c, double identifier) 
        {
            verts[0] = a;
            verts[1] = b;
            verts[2] = c;
            averagePos();
        }
        std::array<vertex, 3> getVerts() {
            std::array<vertex, 3> arr;
            for (int i = 0; i < 3; i++) arr[i] = verts[i];
            return(arr);
        }
        void setVerts(vertex newVerts[]) 
        {
            for (int i = 0; i < 3; i++) verts[i] = newVerts[i];
            averagePos();
        }
        double x;
        double y;
        double z;
        double getID() {
            return(id);
        }
    private:
        vertex verts[3];
        void averagePos() {
            x = verts[0].x + verts[1].x + verts[2].x;
            x = x/3;
            y = verts[0].y + verts[1].y + verts[2].y;
            y = y/3;
            z = verts[0].z + verts[1].z + verts[2].z;
            z = z/3;
        }
        double id;
};