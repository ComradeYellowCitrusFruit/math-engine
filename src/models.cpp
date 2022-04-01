//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Ah yes, models...                                                                                   //
//  Reminds me of blender...                                                                            //
//  those were the days.                                                                                //
//  Anyway time for actual code.                                                                        //
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Of course positions are involved, this is literally where 3d models are defined
#include <cmath>
#include <thread>
#include <mutex>

#include "position.hpp"
#include "constants.hpp"
#include "converters.hpp"
#include "matrix.hpp"
#include "objects.hpp"

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
        tri getTris() {
            return(tris);
        }
        void setTris(tri newTris) {
        }
        vector3D pos;
        int triCount;
        int vertCount;
    private:
        vertex verts[1];
        tri tris[1];
        double id;
        void updateTris(int threads) {
            std::mutex mtx;
            if (threads < sizeof(tris[]) / sizeof(tris[0])) {
                std::thread tri_threads(thr_updateTris, 0, sizeof(tris[]) / sizeof(tris[0], mtx);
                tri_threads.join();
            }
            else {
                int triCount = sizeof(tris[]) / sizeof(tris[0]);
                std::thread tri_threads[threads + 1];
                int trisPerThread = triCount / threads;
                int min = 0;
                if (triCount % threads != 0) {
                    int remainderTriMin = triCount - trisPerThread * threads;
                    for (int i = 0; i <= threads; i++) {
                        if (i = threads) {
                            tri_threads[i] = std::thread(thr_updateTris, remainderTriMin, triCount, mtx);
                        }
                        else {
                            int max = trisPerThread * (i + 1);
                            tri_threads[i] = std::thread(thr_updateTris, min, max, mtx);
                            min = max;
                        }
                    }
                    for (int i = 0; i <= threads; i++) {
                        tri_threads[i].join();
                    }
                }
                else {
                    for (int i = 0; i < threads; i++) {
                        int max = trisPerThread * (i + 1);
                        tri_threads[i] = std::thread(thr_updateTris, min, max, mtx);
                        min = max;
                    }
                }
            }
        }
        void thr_updateTris(int min, int max, std::mutex mtx) {
            std::lockguard<std::mutex> lg (mtx);
            for (int i = min; i < max; i++) {
                for (int j = 0; j < sizeof(tris[]) / sizeof(tris[0]); j++) {
                    for (int k = 0; k < 3; k++) {
                        if (tris[j].verts[k].getID() = verts[i].getID()) {
                            tris[j].verts[k].x = verts[i].x;
                            tris[j].verts[k].y = verts[i].y;
                            tris[j].verts[k].z = verts[i].z;
                            tris[j].averagePos();
                        }
                    }
                }
            }
        }
};