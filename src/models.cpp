//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Ah yes, models...                                                                                   //
//  Reminds me of blender...                                                                            //
//  those were the days.                                                                                //
//  Anyway time for actual code.                                                                        //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Of course positions are involved, this is literally where 3d models are defined
#include "position.hpp"
#include "constants.hpp"
#include "converters.hpp"
#include "matrix.hpp"
#include "objects.hpp"
#include <cmath>
#include <thread>
#include <mutex>
// So, when including this within you project, in order to insure that thread ids are done properly replace the following line with whatever file contains the number of threads.
// #include "core/threads.hpp"

class model {
    public:
        model(vertex vertices[], tri triangles[], vector3D Pos, double ID) {
            id = ID;
            delete[] verts;
            verts = vertices;
            delete[] tris;
            tris = triangles;
            pos = Pos;
            vertCount = (int)(sizeof(vertices)/sizeof(vertices[0]));
            triCount = (int)(sizeof(triangles)/sizeof(triangles[0]));
        }
        vertex getVerts() {
            return(verts);
        }
        void setVerts(vertex newVerts) {
            verts = newVerts;
        }
        tri getTris();
        void setTris(tri newTris);
        vector3D pos;
        int triCount;
        int vertCount;
    private:
        vertex verts[1];
        tri tris[1];
        double id;
        void updateTris(int threads) {
            std::mutex mtx;
        }
        void thr_updateTris(int min, int max, std::mutex mtx) {
            std::lockguard<std::mutex> lg (mtx);
            
        }
};