#include "constants.h"
#include <cmath>

class matrix {
    public:
        int length;
        int height;
        float data[1][1];
        matrix(int l, int h) {
            length = l;
            height = h;
            int* tempData = new int[length][height];
            delete[] data;
            data = tempData;
            tempData = nullptr;
        }
};
