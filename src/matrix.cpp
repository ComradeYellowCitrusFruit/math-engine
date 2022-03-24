#include "constants.h"
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
        matrix &eval(matrix input, int operation) 
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
};