//////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a file for miscellaneous functions with many uses.											//
// These functions are not 'simple' and are likely faster versions of simpler implementations of...     //
// ...various functions.																				//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cstdint>

// A double version of fast inverse square root from Quake III: Arena. Source code from https://stackoverflow.com/questions/11644441/fast-inverse-square-root-on-x64
double Q_rsqrt(double number)
{
    double y = number;
    double x2 = y * 0.5;
    std::int64_t i = *(std::int64_t*) & y;
    // The magic number is for doubles is from https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    y = *(double*)&i;
    y = y * (1.5 - (x2 * y * y));   // 1st iteration
    //      y  = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}