#ifndef MATH_MATRIX
#define MATH_MATRIX

#include <cmath>
#include <vector>

#include "constants.hpp"
#include "matrix.hpp"
#include "position.hpp"

class matrix {
    public:
        matrix(int r, int c);
        double getData();
        void setData(double a[][], int r, int c, bool clearMatrix = false);

        matrix &scalarMulti(double input);
        matrix &transposition();
        matrix &remove(int r[], int c[]);

        matrix operator+(const matrix &my);
        matrix operator-(const matrix &my);
        matrix operator*(const matrix &input);
        matrix operator*(const vector2D &v);
        matrix operator*(const vector3D &v);
        matrix operator*(const vector4D &v);
        matrix operator*(double a);
        // There is no such thing as official matrix division, however that does not matter, this is just the inverse of scalar division
        matrix operator/(const double& d);
        bool operator==(const matrix &m);
        bool operator!=(const matrix &m);
        matrix operator<<(double x);
        double operator>>(double x);
        matrix operator>>(matrix m);
        matrix operator%(double a[][]);
        matrix operator^(const int& x);
        void operator<<(const matrix& m);

        vector2D toVector2D();
        vector3D toVector3D();
        vector4D toVector4D();
        double determinant();
        matrix& bareissAlgorithm();
    private:
        int row;
        int column;
        double data[1][1];
        double dotProduct(double x[], double y[]);
};

matrix &generateRxMatrix(double x);
matrix &generateRyMatrix(double x);
matrix &generateRzMatrix(double x);
#endif
