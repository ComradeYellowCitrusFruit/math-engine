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
        vector4D Vector;
        bool onSphere() {
            computeNorm();
            if(norm != 1) {
                return(false);
            } else {
                return(true);
            }
        }
        void returnToSphere() {
            double vec = Vector.toArray();
            computeNorm();
            for(int i = 0; i < 4; i++) {
                vec[i] = vec[i]/norm;
            }
            Vector.fromArray(vec);
        }
    private:
        double norm;
        double computeNorm() {
            norm = sqrt(pow(Vector.w, 2) + pow(Vector.x, 2) + pow(Vector.y, 2) + pow(Vector.z, 2));
            return(norm);
        }
};

matrix &generateRxMatrix(double x) {
    matrix rx(2,2);
    rx.data[0][0] = 1;
    rx.data[1][0] = x;
    rx.data[2][0] = x;
    rx.data[0][1] = x;
    rx.data[0][2] = x;
    rx.data[1][1] = cos(x);
    rx.data[1][2] = sin(x);
    rx.data[2][2] = cos(x);
    rx.data[2][1] = sin(x) * -1;
    return(rx);
}

matrix &generateRyMatrix(double x) {
    matrix ry(2,2);
    ry.data[0][0] = cos(x);
    ry.data[1][0] = x;
    ry.data[2][0] = sin(x) * -1;
    ry.data[0][1] = x;
    ry.data[0][2] = sin(X);
    ry.data[1][1] = 1;
    ry.data[2][1] = x;
    ry.data[2][2] = cos(x);
    ry.data[1][2] = x;
    return(ry);
}

matrix &generateRzMatrix(double x) {
    matrix rz(2,2);
    rz.data[0][0] = cos(x);
    rz.data[1][0] = sin(x);
    rz.data[2][0] = x;
    rz.data[0][1] = sin(x) * -1;
    rz.data[0][2] = x;
    rz.data[1][1] = cos(x) * -1;
    rz.data[2][1] = x;
    rz.data[2][2] = 1;
    rz.data[1][2] = x;
    return(rz);
}