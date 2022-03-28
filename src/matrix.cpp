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
        matrix operator+(const matrix &my) {
            matrix ret(this.row, this.column)
            if(this.column != my.column) 
            {
                return(this);
            } 
            else if(this.row != my.row)
            {
                return(this);
            }
            for(int i = 0; i < this.row; i++)
            {
                for(int j = 0; j < my.column; i++) {
                    ret.data[i][j] = mx.data[i][j] + my.data[i][j];
                }
            }
            return(ret);
        }
        matrix operator-(const matrix &my) {
            matrix ret(this.row, this.column)
            if(this.column != my.column) 
            {
                return(this);
            } 
            else if(this.row != my.row)
            {
                return(this);
            }
            for(int i = 0; i < this.row; i++)
            {
                for(int j = 0; j < my.column; i++) {
                    ret.data[i][j] = mx.data[i][j] - my.data[i][j];
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
        matrix operator*(const matrix &input) {
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
        matrix operator/(const double &d) {
            matrix r(this.row, this.column);
            for(int i=0; i < row; i++) {
                for(int j=0; j < column; j++) {
                    r.data[i][j] = this.data[i][j]/d;
                }
            }
            return(r);
        }
        bool operator==(const matrix &m) {
            if(this.row != m.row) {
                return(false);
            } else if (this.column != m.column) {
                return(false);
            }
            for(int i=0; i < this.row; i++) {
                for(int j=0; j < this.column; j++) {
                    if(this.data[i][j] != m.data[i][j]) {
                        return(false);
                    }
                }
            }
            return(true);
        }
        bool operator!=(const matrix &m) {
            if(this.row != m.row) {
                return(true);
            } else if (this.column != m.column) {
                return(true);
            }
            for(int i=0; i < this.row; i++) {
                for(int j=0; j < this.column; j++) {
                    if(this.data[i][j] != m.data[i][j]) {
                        return(true);
                    }
                }
            }
            return(false);
        }
        matrix operator<<(double x) {
            for(int i=0; i < this.row; i++) {
                for(int j=0; j < this.column; j++) {
                    if(this.data[i][j] == NULL || this.data[i][j] == 0) {
                        this.data[i][j] = x;
                        return(this);
                    }
                }
            }
        }
        double operator>>() {
            for(int i=this.row; i > 0; i--) {
                for(int j=this.column; j > 0; j--) {
                    if(this.data[i][j] != NULL || this.data[i][j] != 0) {
                        double x = this.data[i][j];
                        this.data[i][j] = NULL;
                        return(x);
                    }
                }
            }
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