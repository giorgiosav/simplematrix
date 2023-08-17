#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

#include <type_traits>
#include <memory>
#include <initializer_list>
#include <ostream>

namespace SimpleMatrix {
    using std::unique_ptr;
    using std::initializer_list;
    using std::ostream;

    class Matrix {
        public:
            Matrix(int nrows, int ncols);
            Matrix(initializer_list<initializer_list<double>> il);

            int nrows() const;
            int ncols() const;

            double& operator()(int row, int col);
            double operator()(int row, int col) const;
            Matrix operator+(Matrix const& other) const;
            Matrix operator*(Matrix const& other) const;
            void operator+=(Matrix const& other);
            void operator*=(double s);
            Matrix operator*(double s);
            
            bool operator==(Matrix const& other) const;
            Matrix clone() const;
            
            friend Matrix zeros(int nrows, int ncols);
        private:
            unique_ptr<double[]> _storage;
            int _nrows;
            int _ncols;

    };

    Matrix zeros(int nrows, int ncols);
    Matrix new_like(Matrix const& other);
    ostream& operator<<(ostream& out, Matrix const& m);
    
}


#endif // SIMPLEMATRIX_H