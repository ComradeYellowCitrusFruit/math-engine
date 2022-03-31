#include "simple.hpp"
#include <cmath>
#include "constants.hpp"
#include "converters.hpp"

// Factorial of int x
int factorial(int x) {
    if(x == 0 || x == 1) {
        return(1);
    }
    int r=x;
    for(int i=1; i < x; i++) {
        r *= (x-i);
    }
    return(r);
}

// Factorial but as a double, and excepting a varible for step.
double factorialWS(double x, double step) {
    if(x == 0) {
        return(1);
    }
    double r=x;
    for(int i=1; i < x; i + step) {
        r *= (x-i);
    }
    return(r);
}

// Does the actual math for the golden ratio, if you need some extra precision
long double preciseGoldenRatio() {
    double x = sin(angleConverter(54, 'd'));
    long double y = 2*(long double)x;
    return(y);
}

// Does the actual math for pi with 52 digits of accuracy, which is over kill but if you want 52 digits of accuracy then you can have it.
long double precisePI() {
    double x = 236674 + 30303*sqrt(61);
    x = pow(x, 3);
    x *= pow(5280, 3);
    x += 744;
    x = log(x);
    double y = sqrt(427);
    long double X = (long double)x;
    long double Y = (long double)y;
    long double z = X/Y;
    return(z)
}

// Does the actual math for pi with 161 digits of accuracy, by all means beyond over kill but you do you I guess
long double overkillPI() {
    double a = 23 + 4 * sqrt(34);
    a *= 1/2;
    double b = 19 * SQRT2 + 7 * sqrt(17);
    b *= 1/2;
    double c = 429 + 304 * SQRT2;
    double d = 627 + 442 * SQRT2;
    d *= 1/2;
    double u = pow(a + sqrt(a*a-1), 2) * pow(b + sqrt(b*b-1), 2) * (c + sqrt(c*c-1)) * (d + sqrt(d*d-1))
    long double x = (long double)(log(pow(2*u,6) + 24))
    long double y = (long double)(sqrt(3502))
    return(x/y)
}

// Why do I keep adding more versions of Pi?
long double superOverKillPI() {
    double x = 6 * atan(1/8) + 2 * atan(1/57) + atan(1/239);
    long double y = 4 * (long double)x;
    return(y);
}