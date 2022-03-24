#include "constants.h"
#include <cmath>

class matrix {
    public:
        int row;
        int column;
        float data[1][1];
        matrix(int r, int c) {
            row = r;
            column = c;
            int* tempData = new int[row][column];
            delete[] data;
            data = tempData;
            tempData = nullptr;
        }
};
