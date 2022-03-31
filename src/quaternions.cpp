//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enter quaternions.                                                                                   //
// Since my days as a (wannabe) game dev, I feared quaternions.                                         //
// They confused me, made my life difficult, made it hell for a young, innocent game dev.               //
// I thought I left them behind, but here I am, once again face to face with quaternions.               //
// May God have mercy on my soul.                                                                       //
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cmath>
#include "simple.hpp"
#include "position.hpp"
#include "constants.hpp"
#include "matrix.hpp"

class quaternion {
    public:
        double w, x, y, z;
        bool onSphere() {
            computeNorm();
            if(norm != 1) {
                return(false);
            } else {
                return(true);
            }
        }
        void returnToSphere() {
            computeNorm();
            for(int i = 0; i < 4; i++) {
                vec[i] = vec[i]/norm;
            }
            w = w/norm;
            x = x/norm;
            y = y/norm;
            z = z/norm;
        }
        double &conjugate() {
            return(w - x - y - z);
        }
        quaternion operator+(const quaternion &b) {
            quaternion r;
            r.w = this.w + b.w;
            /*
            double arrB[4] = b.qw.toArray();
            double arrA[4] = this.qw.toArray();
            double arrC[4];
            for(int i = 0; i < 4; i++) {
                arrC[i] = arrA[i] + arrB[i];
            }
            r.qw.fromArray(arrC);
            double arrD[3] = {arrC[1], arrC[2], arrC[3]};
            r.q.fromArray(arrD);
            */
            r.x = this.x + b.x;
            r.y = this.y + b.y;
            r.z = this.z + b.z;
            return(r);
        }
        quaternion operator*(const quaternion &b) {
            quaternion r;
            double w = this.w * b.w - this.x * b.x - this.y * b.y - this.z * b.z;
            double x = this.w * b.x + this.x * b.w + this.y * b.z - this.z * b.y;
            double y = this.w * b.y - this.x * b.z + this.y * b.w + this.z * b.x;
            double z = this.w * b.z + this.x * b.y - this.y * b.w + this.z * b.w;
            r.w = w;
            r.x = x;
            r.y = y;
            r.z = z;
            return(r);
        }
        vector3D toEuler() {
            vector3D v;
            double a = w * x + y * z;
            double b = x * x + y * y;
            v.x = atan2(a * 2, 1 - b * 2);
            a = w * y + z * x;
            v.y = asin(a * 2);
            a = w * z + x * y;
            b = y * y + z * z;
            v.z = atan2(a * 2, 1 - b * 2);
            return(v);
        }
    private:
        double norm;
        double computeNorm() {
            norm = sqrt(pow(qw.w, 2) + pow(qw.x, 2) + pow(qw.y, 2) + pow(qw.z, 2));
            return(norm);
        }
};