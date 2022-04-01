#include <cmath>
#include "constants.hpp"

double angleConverter(double x, char RorD) {
    if(RorD == 'r' || RorD == 'R') {
        return(x * 180/PI);
    } else if(RorD == 'd' || RorD == 'D') {
        return(x * PI/180);
    } else {
        return(0);
    }
}
// This probably won't be necessary, but just in case
double temperature(double x, char type, char to) {
    if(type == 'f' || type == 'F') {
        if(to == 'c' || to == 'C') {
            return((x - 32) * 5 / 9);
        } else if(to == 'k' || to == 'K') {
            return((x - 32) * 5 / 9 + 273.15);
        }
    } else if(type == 'c' || type == 'C') {
        if(to == 'f' || to == 'F') {
            return(x * 9 / 5 + 32);
        } else if(to == 'k' || to == 'K') {
            return(x + 273.15);
        }
    } else if(type == 'k' || type == 'K') {
        if(to == 'f' || to == 'F') {
            return((x - 273.15) * 9 / 5 + 32);
        } else if(to == 'c' || to == 'c') {
            return(x - 273.15);
        }
    }
}
// This will likely come in handy for the user and if we make our own physics engine
double distance(double x, char type, char to) {
}