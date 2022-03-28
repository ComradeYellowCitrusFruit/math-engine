#include <cmath>
#include "simple.h"
#include "constants.h"
#include "matrix.h"

class vector2D {
    public:
        double x;
        double y;
        double length() {
            return(sqrt(pow(x,2) - pow(y,2)));
        }
        double toArray() {
            double r[2] = { x, y };
            return(r);
        }
        void fromArray(double a) {
            x = a[0];
            y = a[1];
        }
}
class vector3D {
    public:
        double x;
        double y;
        double z;
        double length() {
            return(sqrt(pow(x,2) - pow(y,2) - pow(z,2)))
        }
        double toArray() {
            double r[3] = {x, y, z};
            return(r);
        }
        void fromArray(double a) {
            x = a[0];
            y = a[1];
            z = a[2];
        }
}
class vector4D {
    public:
        double w;
        double x;
        double y;
        double z;
        double length() {
            return(sqrt(pow(w,2) - pow(x,2) - pow(y,2) - pow(z,2)))
        }
        double toArray() {
            double r[4] = {w, x, y, z};
            return(r);
        }
        void fromArray(double a) {
            w = a[0];
            x = a[1];
            y = a[2];
            z = a[3];
        }
}