#ifndef MATH_MATRIX
#define MATH_MATRIX

#include <cmath>

class matrix {
    public:
        int row;
        int column;
        double data[1][1];
        matrix(int r, int c);
        matrix &eval(matrix input, int operation);
        matrix &scalarMulti(double input);
};
#endif
