#include <cmath>
#include <array>
#include "position.hpp"
#include "simple.hpp"
#include "constants.hpp"

class vector2D 
{
    public:
        double x;
        double y;
        std::array<double, 2> toArray() 
        {
            std::array<double, 2> r = { x, y };
            return(r);
        }
        void fromArray(double a[]) {
            x = a[0];
            y = a[1];
        }
        double magnitude() {
            return(sqrt(pow(x, 2) + pow(y, 2)));
        }
};
class vector3D 
{
    public:
        double x;
        double y;
        double z;
        std::array<double, 3> toArray() 
        {
            std::array<double, 3> r = { x, y, z };
            return(r);
        }
        void fromArray(double a[]) {
            x = a[0];
            y = a[1];
            z = a[2];
        }
        double magnitude() {
            return(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
        }
};
class vector4D 
{
    public:
        double w;
        double x;
        double y;
        double z;
        std::array<double, 4> toArray() 
        {
            std::array<double, 4> r = { w, x, y, z };
            return(r);
        }
        void fromArray(double a[]) {
            w = a[0];
            x = a[1];
            y = a[2];
            z = a[3];
        }
        double magnitude() {
            return(sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2)));
        }
};

vector3D &crossProduct(vector3D a, vector3D b) {
    vector3D c;
    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return(c);
}

double vector3dDotProduct(vector3D a, vector3D b) {
    double r = a.x * b.x + a.y * b.y + a.z * b.z;
    return(r);
}

double vector2dDotProduct(vector2D a, vector2D b) {
    double r = a.x * b.x + a.y * b.y;
    return(r);
}

double vector3dAngle(vector3D x, vector3D y) {
    double a = x.x * y.x + x.y * y.y + x.z * y.z;
    double d = sqrt(x.magnitude()) * sqrt(y.magnitude());
    double r = a/d;
    return(acos(r));
}