#include "constants.h"
#include "matrix.h"
#include <cmath>
#include <vector>

class matrix {
    public:
        int row;
        int column;
        double data[1][1];
        matrix(int r, int c) {
            row = r;
            column = c;
            double *tempData = new double[row][column];
            delete[] data;
            data = tempData;
            tempData = nullptr;
        }
        matrix &addSub(matrix input, int operation) 
        {
            // Operation codes:
            // Addition: 1
            // Subtraction: 2
            if(input.column != column) 
            {
                matrix self(row, column);
                self.data = data;
                return(self);
            } 
            else if(input.row != row)
            {
                matrix self(row, column);
                self.data = data;
                return(self);
            }
            matrix ret(row, column);
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; i++) {
                    if(operation = 1) {
                        ret.data[i][j] = data[i][j] + input.data[i][j];
                    } else if(operation = 2) {
                        ret.data[i][j] = data[i][j] - input.data[i][j];
                    } else {
                        matrix self(row, column);
                        self.data = data;
                        return(self)
                    }
                }
            }
            return(ret);
        }
        matrix &scalarMulti(double input) {
            matrix m(row, column);
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < column; i++) {
                    m.data[i][j] = data[i][j] * input;
                }
            }
            return(m);
        }
        matrix &transposition() {
            matrix t(column, row);
            for(int i=0; i < column; i++) {
                for(int j=0; j < row; j++) {
                    t.data[i][j] = data[j][i]
                }
            }
            return(t);
        }
        matrix &remove(int r[], int c[]) {
            matrix r(row - sizeof(r), column - sizeof(c));
            int sub[1] = {0, 0};
            for(int i=0; i < row; i++) {
                for(int j=0; j < column; j++) {
                    for(int x; x < sizeof(r); x++) {
                        for(int y; y < sizeof(c); y++) {
                            if(i != r[x] && j != c[y]) {
                                r.data[i - sub[0]][j - sub[1]] = data[i][j]
                            } else {
                                if(i == r[x]) {
                                    sub[0]++
                                }
                                if(j == c[y]) {
                                    sub[1]++
                                }
                            }
                        }
                    }
                }
            }
            return(r);
        }
        matrix &multiply(matrix input) {
            if(column != input.row) {
                matrix r(row, column);
                r.data = data
                return(r);
            }
            matrix r(column, input.row)
            double a[row][column];
            for(int i=0; i < row; i++) {
                a[i] = data[i]
            }
            std::vector<double> bv[input.column];
            double b[input.column][input.row];
            for(int i=0; i < input.column; i++) {
                for(int j=0; j < input.row; j++) {
                    bv[i].push_back(input.data[j][i])
                }
            }
            for(int i=0; i < input.column; i++) {
                for(int j=0; j < input.row; j++) {
                    b[i][j] = bv[i].at(j);
                }
            }
            for(int i=0; i < r.row; i++) {
                for(int j=0; j < r.column; j++) {
                    r.data[i][j] = dotProduct(a[i], b[j]);
                }
            }
            return(r);
        }
        // There is no such thing as official matrix division, however that does not matter, this is just the inverse of scalar division
        matrix &scalarDiv(double d) {
            matrix r(row, column);
            for(int i=0; i < row; i++) {
                for(int j=0; j < column; j++) {
                    r.data[i][j] = data[i][j]/d;
                }
            }
            return(r);
        }
    private:
        double dotProduct(double x[], double y[]) {
            double r = 0;
            for(int i=0; i < sizeof(x); i++) {
                r += x[i] * y[i];
            }
            return(r);
        }
};

matrix &generateRxMatrix(double x) {
    matrix rx(2,2);
    rx.data[0][0] = 1;
    rx.data[1][0] = x;
    rx.data[2][0] = x;
    rx.data[0][1] = x;
    rx.data[0][2] = x;
    rx.data[1][1] = cos(x);
    rx.data[1][2] = sin(x);
    rx.data[2][2] = cos(x);
    rx.data[2][1] = sin(x) * -1;
    return(rx);
}

matrix &generateRyMatrix(double x) {
    matrix ry(2,2);
    ry.data[0][0] = cos(x);
    ry.data[1][0] = x;
    ry.data[2][0] = sin(x) * -1;
    ry.data[0][1] = x;
    ry.data[0][2] = sin(X);
    ry.data[1][1] = 1;
    ry.data[2][1] = x;
    ry.data[2][2] = cos(x);
    ry.data[1][2] = x;
    return(ry);
}

matrix &generateRzMatrix(double x) {
    matrix rz(2,2);
    rz.data[0][0] = cos(x);
    rz.data[1][0] = sin(x);
    rz.data[2][0] = x;
    rz.data[0][1] = sin(x) * -1;
    rz.data[0][2] = x;
    rz.data[1][1] = cos(x) * -1;
    rz.data[2][1] = x;
    rz.data[2][2] = 1;
    rz.data[1][2] = x;
    return(rz);
}