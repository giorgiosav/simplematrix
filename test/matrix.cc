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


int main() {
    construct();
}