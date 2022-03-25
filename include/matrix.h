#ifndef MATH_MATRIX
#define MATH_MATRIX

#include <cmath>

class matrix {
    public:
        int row;
        int column;
        double data[1][1];
        matrix(int r, int c);
        matrix &addSub(matrix input, int operation);
        matrix &scalarMulti(double input);
        matrix &transposition();
        matrix &remove(int r[], int c[]);
        matrix &multiply(matrix input);
    private:
        double dotProduct(double x[], double y[]);
};
#endif
