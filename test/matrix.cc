#include <assert.h>
#include "simplematrix.h"

using namespace SimpleMatrix;

void construct() {
    constexpr int nrows = 12;
    constexpr int ncols = 17;
    Matrix m(12, 17);

    assert(m.nrows() == nrows);
    assert(m.ncols() == ncols);
}

void construct_il() {
    Matrix m({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}});

    int k = 1;
    for (int i = 0; i < 4; ++i) {
        for(int j = 0; j < 3; ++j) {
            assert(m(i, j) == k);
            ++k;
        }
    }
}


int main() {
    construct();
    construct_il();
}