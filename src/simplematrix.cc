
#include "simplematrix.h"

namespace SimpleMatrix {

    Matrix::Matrix(int nrows, int ncols) :
        _storage(new double[nrows * ncols]),
        _nrows(nrows),
        _ncols(ncols) 
    {}

    Matrix::~Matrix() {}

    int Matrix::nrows() const {
        return _nrows;
    }

    int Matrix::ncols() const {
        return _ncols;
    }

}
