#include "constants.h"
#include "matrix.h"
#include <cmath>

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
            
        }
    private:
        double dotProduct(double x[], double y[]) {
            if(sizeof(x) != sizeof(y)) return(0);
            double r = 0;
            for(int i=0; i < sizeof(x); i++) {
                r += x[i] * y[i];
            }
            return(r);
        }
};