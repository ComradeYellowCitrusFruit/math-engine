//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enter quaternions.                                                                                   //
// Since my days as a (wannabe) game dev, I feared quaternions.                                         //
// They confused me, made my life difficult, made it hell for a young, innocent game dev.               //
// I thought I left them behind, but here I am, once again face to face with quaternions.               //
// May God have mercy on my soul.                                                                       //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cmath>
#include "simple.h"
#include "environment.h"
#include "constants.h"
#include "matrix.h"

class quaternion {
    public:
        vector4D qw;
        vector3D q;
        double w;
        bool onSphere() {
            computeNorm();
            if(norm != 1) {
                return(false);
            } else {
                return(true);
            }
        }
        void returnToSphere() {
            double vec = qw.toArray();
            computeNorm();
            for(int i = 0; i < 4; i++) {
                vec[i] = vec[i]/norm;
            }
            Vector.fromArray(vec);
        }
        quaternion &conjugate() {

        }
    private:
        double norm;
        double computeNorm() {
            norm = sqrt(pow(qw.w, 2) + pow(qw.x, 2) + pow(qw.y, 2) + pow(qw.z, 2));
            return(norm);
        }
};