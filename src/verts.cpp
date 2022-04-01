//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  So, here we are, vertices, the building blocks of polygons, and therefore 3d models                 //
//  The first circle of our little hell.                                                                //
//  These are basically fancy vectors for our purposes right now.                                       //
//  Triangles will serve to break down polygons as well                                                 //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <thread>
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
        tri(vertex a, vertex b, vertex c, double identifier) {
            verts = { a, b, c };
            averagePos();
        }
        vertex getVerts() {
            return(verts);
        }
        void setVerts(vertex newVerts) {
            verts = newVerts;
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
            x = a.x + b.x + c.x;
            x = x/3;
            y = a.y + b.y + c.y;
            y = y/3;
            z = a.z + b.z + c.z;
            z = z/3;
        }
        double id;
};