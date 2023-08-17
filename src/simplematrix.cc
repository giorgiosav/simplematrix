
#include <cassert>
// #include <iostream>

#include "simplematrix.h"


namespace SimpleMatrix {

    Matrix new_like(Matrix const& other) {
        return Matrix(other.nrows(), other.ncols());
    }

    Matrix zeros(int nrows, int ncols) {
        Matrix m(nrows, ncols);
        memset(m._storage.get(), 0, sizeof(double) * nrows * ncols);
        return m;
    }

    ostream& operator<<(ostream& out, Matrix const& m) {

        for (int i = 0; i < m.nrows(); ++i) {
            for(int j = 0; j < m.ncols(); ++j) {
                out << m(i, j) << " ";
            }
            out << '\n';
        }

        return out;
    }

    Matrix::Matrix(int nrows, int ncols) :
        _storage(new double[nrows * ncols]),
        _nrows(nrows),
        _ncols(ncols) 
    {}

    Matrix::Matrix(initializer_list<initializer_list<double>> il) {

        _nrows = il.size();
        auto it = il.begin();

        _ncols = it->size();
        double* storage = new double[_nrows * _ncols];
        int row = 0;

        while (it != il.end()) {
            // TODO should be a user error?
            assert(it->size() == static_cast<size_t>(_ncols));
            
            int col = 0;
            for (double n: *it) {
                storage[row * _ncols + col] = n;
                ++col;
            }
            ++row;
            ++it;
        }

        _storage.reset(storage);
    }


    int Matrix::nrows() const {
        return _nrows;
    }

    int Matrix::ncols() const {
        return _ncols;
    }

    Matrix Matrix::clone() const {
        Matrix m = new_like(*this);
        memcpy(m._storage.get(), _storage.get(), _nrows * _ncols * sizeof(double));
        return m;
    }


    double& Matrix::operator()(int row, int col) {
        return _storage[row * _ncols + col];
    }

    double Matrix::operator()(int row, int col) const {
        return _storage[row * _ncols + col];
    }

    void Matrix::operator+=(Matrix const& other) {
        assert(other.nrows() == _nrows && other.ncols() == _ncols);

        for (int i = 0; i < _nrows; ++i) {
            for(int j = 0; j < _ncols; ++j) {
                this->operator()(i, j) += other(i, j);
            }
        }
    }

    Matrix Matrix::operator+(Matrix const& other) const {
        Matrix m = this->clone();
        m += other;
        return m;
    }

    Matrix Matrix::operator*(Matrix const& other) const {
        assert(_ncols == other.nrows());
        Matrix m(_nrows, other.ncols());

        for (int i = 0; i < m.nrows(); ++i) {
            for (int j = 0; j < m.ncols(); ++j) {
                double acc = 0;

                for (int ti = 0; ti < _ncols; ++ti) {
                    acc += this->operator()(i, ti) * other(ti, j);
                }

                m(i, j) = acc;
            }
        }

        return m;
    }

    void Matrix::operator*=(double s) {
        for (int i = 0; i < _nrows; ++i) {
            for (int j = 0; j < _ncols; ++j) {
                _storage[i * _ncols + j] *= s;
            }
        }
    }

    Matrix Matrix::operator*(double s) {
        Matrix m = this->clone();
        m *= s;
        return m;
    }

    bool Matrix::operator==(Matrix const& other) const {
        if (_ncols != other.ncols() || _nrows != other.nrows()) {
            return false;
        }

        for (int i = 0; i < _nrows * _ncols; ++i) {
            if (_storage[i] != other._storage[i]) return false;
        }

        return true;
    }
            

}
