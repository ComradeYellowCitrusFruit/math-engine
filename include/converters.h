#include "constants.h"
#include <cmath>

class angleConverter {
    public:
        angle(double x, char RorD);
        double toRad();
        double toRad(double d);
        double toDeg();
        double toDeg(double r);
    private:
        double degrees;
        double radians;
}