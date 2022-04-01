#include <cmath>
#include <vector>
#include <src/vectors.cpp>
#include "constants.hpp"
#include "matrix.hpp"
#include "position.hpp"

class matrix {
    public:
        matrix(int r, int c) {
            row = r;
            column = c;
            
        }
        double getData() {
            return(data);
        }
        void setData(double a[][], int r, int c, bool clearMatrix = false) {
            if(r == row && c == column) {
                data = a;
            } else if(clearMatrix = true) {
                row = r;
                column = c;
                double* tempData = new double[row][column];
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < column; j++) {
                        tempData[i][j] = a[i][j];
                    }
                }
                double* temp = data;
                data = tempData;
                delete[] temp;
            }
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
            matrix r(row - sizeof(r)/4, column - sizeof(c)/4);
            int sub[1] = {0, 0};
            for(int i=0; i < row; i++) {
                for(int j=0; j < column; j++) {
                    for(int x; x < sizeof(r)/4; x++) {
                        for(int y; y < sizeof(c)/4; y++) {
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
            if(this.column != input.row) {
                return(this);
            }
            matrix r(this.column, input.row)
            double a[this.row][this.column];
            for(int i=0; i < this.row; i++) {
                a[i] = data[i];
            }
            std::vector<double> bv[input.column];
            double b[input.column][input.row];
            for(int i=0; i < input.column; i++) {
                for(int j=0; j < input.row; j++) {
                    bv[i].push_back(input.data[j][i]);
                }
            }
            for(int i=0; i < input.column; i++) {
                for(int j=0; j < input.row; j++) {
                    b[i][j] = bv[i].at(j);
                }
            }
            for(int i=0; i < r.row; i++) {
                for(int j=0; j < r.column; j++) {
                    r << dotProduct(a[i], b[j]);
                }
            }
            return(r);
        }
        matrix operator*(const vector2D &v) {
            return(this * v.toMatrix());
        }
        matrix operator*(const vector3D &v) {
            return(this * v.toMatrix());
        }
        matrix operator*(const vector4D &v) {
            return(this * v.toMatrix());
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
        double operator>>(double x) {
            for(int i=this.row; i > 0; i--) {
                for(int j=this.column; j > 0; j--) {
                    if(this.data[i][j] != NULL || this.data[i][j] != 0) {
                        x = this.data[i][j];
                        return(x);
                    }
                }
            }
        }
        matrix operator>>(matrix m) {
            for(int i=this.row; i > 0; i--) {
                for(int j=this.column; j > 0; j--) {
                    if(this.data[i][j] != NULL || this.data[i][j] != 0) {
                        m << this.data[i][j];
                    }
                }
            }
            return(m);
        }
        matrix operator%(double a[][]) {
            return(this.remove(a[0], a[1]));
        }
        matrix operator*(double a) {
            matrix r(this.row, this.column);
            for(int i = 0; i < this.row; i++) {
                for(int j = 0; j < this.column; j++) {
                    r.data[i][j] = this.data[i][j] * a;
                }
            }
            return(r);
        }
        double determinant() {
            double m = bareissAlgorithm().getData();
            return(m[row-1][column-1]);
        }
        matrix& bareissAlgorithm() {
            if (row != column) return(NULL);
            double m = getData();
            m[0][0] = 1;
            for (int k = 1; k < row - 1; k++) {
                for (int i = 0; k + 1 < row; i++) {
                    for (int j = 0; k + 1 < row) {
                        double d = m[i][j] * m[k][k] - m[i][k] * m[k][j]; // Ha ha titties ha ha
                        double e = m[k - 1][k - 1];
                        m[i][j] = d / e;
                    }
                }
            }
            matrix self(row, column);
            self.setData(m, row, column);
            return(self);
        }
        matrix operator^(const int &x) {
            if(x < 0) {
                if(determinant() == NULL || determinant() == 0) return(this);
                if(row == 2) return(this * 1/determinant());
                matrix self(row, column);
                self.setData(bareissAlgorithm().getData(), row, column);
                if (row < column) {
                    self << generateIDMatrix(column);
                }
                else {
                    self << generateIDMatrix(row);
                }
                
                return();
            }

        }
        void operator<<(const matrix &m) {
            matrix r(this.row + m.row, this.column + m.column);
            double arrA = this.toArray();
            double arrB = m.toArray();
            bool thisNext = true;
            int A = 0;
            int B = 0;
            for(int i = 0; i < sizeof(arrA)/8 + sizeof(arrB)/8; i++) {
                if(i%this.column == 0 && thisNext == false) {
                    thisNext = true;
                } else if(i%m.column == 0 && thisNext == true) {
                    thisNext = false;
                }
                if(thisNext) {
                    r << arrA[A];
                    A++;
                } else {
                    r << arrB[B];
                    B++;
                }
            }
            this.setData(r.getData(), r.row, r.column, true);
        }
        vector2D toVector2D() {
            if(this.rows == 2) {
                double x;
                double y;
                for(int i=0; i < this.columns; i++) {
                    x += this.data[0][i];
                    y += this.data[1][i];
                }
                vector2D r;
                r.x = x;
                r.y = y;
                return(r);
            }
        }
        vector3D toVector3D() {
            if(this.rows == 3) {
                double x;
                double y;
                double z;
                for(int i=0; i < this.columns; i++) {
                    x += this.data[0][i];
                    y += this.data[1][i];
                    z += this.data[2][i];
                }
                vector3D r;
                r.x = x;
                r.y = y;
                r.z = z;
                return(r);
            }
        }
        vector4D toVector4D() {
            if(this.rows == 4) {
                double w;
                double x;
                double y;
                double z;
                for(int i=0; i < this.columns; i++) {
                    w += this.data[0][i];
                    x += this.data[1][i];
                    y += this.data[2][i];
                    z += this.data[3][i];
                }
                vector4D r;
                r.w = w;
                r.x = x;
                r.y = y;
                r.z = z;
                return(r);
            }
        }
        double toArray() {
            double arrA[this.row + this.column];
            double arrB = this.getData();
            int seg;
            for(int i=0; i < this.row; i++) {
                for(int j=0; j < this.column; j++) {
                    arrA[seg] = arrB[i][j];
                }
            }
            return(arrA);
        }
    private:
        int row;
        int column;
        double data[1][1];
        double dotProduct(double x[], double y[]) {
            double r = 0;
            for(int i=0; i < sizeof(x); i++) {
                r += x[i] * y[i];
            }
            return(r);
        }
};

matrix &generateRxMatrix(double x) {
    matrix rx(3,3);
    rx << 1;    rx << 0;            rx << 0;
    rx << 0;    rx << cos(x);       rx << sin(x) * -1;
    rx << 0;    rx << sin(x);       rx << cos(x);
    return(rx);
}

matrix &generateRyMatrix(double x) {
    matrix ry(3,3);
    /*
    ry.data[0][0] = cos(x);
    ry.data[1][0] = x;
    ry.data[2][0] = sin(x) * -1;
    ry.data[0][1] = x;
    ry.data[0][2] = sin(X);
    ry.data[1][1] = 1;
    ry.data[2][1] = x;
    ry.data[2][2] = cos(x);
    ry.data[1][2] = x;
    */
    ry << cos(x);           ry << 0;    ry << sin(x);
    ry << 0;                ry << 1;    ry << 0;
    ry << sin(x) * -1;      ry << 0;    ry << cos(x);
    return(ry);
}

matrix &generateRzMatrix(double x) {
    matrix rz(2,2);
    /*
    rz.data[0][0] = cos(x);
    rz.data[1][0] = sin(x);
    rz.data[2][0] = x;
    rz.data[0][1] = sin(x) * -1;
    rz.data[0][2] = x;
    rz.data[1][1] = cos(x) * -1;
    rz.data[2][1] = x;
    rz.data[2][2] = 1;
    rz.data[1][2] = x;
    */
    rz << cos(x);   rz << sin(x) * -1;      rz << 0;
    rz << sin(x);   rz << cos(x);      rz << 0;
    rz << 0;        rz << 0;                rz << 1;
    return(rz);
}

matrix &generateIDMatrix(double x) {
    matrix i(x,x);
    double m = i.getData();
    for(int j=0; j < x; j++) {
        m[j][j] = 1;
    }
    for(int k=0; k < x; k++) {
        for(int j=0; j < x; j++) {
            if(m[k][j] != 1) {
                m[k][j] = 0;
            }
        }
    }
    i.setData(m, x, x);
    return(i);
}