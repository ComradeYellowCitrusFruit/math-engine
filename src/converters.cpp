#include "constants.h"
#include <cmath>

class angleConverter {
    public:
        angle(double x, char RorD) {
            if(RorD == 'r' || RorD == 'R') {
                radians = x;
            }
        }
        double toRad() {
            return(degrees * PI/180);
        }
        double toRad(double d) {
            return(d * PI/180);
        }
        double toDeg() {
            return(radians * 180/PI)
        }
        double toDeg(double r) {
            return(radians * 180/PI)
        }
    private:
        double degrees;
        double radians;
}