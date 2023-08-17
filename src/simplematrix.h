#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

#include <type_traits>
#include <memory>

namespace SimpleMatrix {
    using std::unique_ptr;

    class Matrix {
        public:
            Matrix(int nrows, int ncols);
            ~Matrix();

            int nrows() const;
            int ncols() const;

        private:
            unique_ptr<double[]> _storage;
            int _nrows;
            int _ncols;

    };
}


#endif // SIMPLEMATRIX_H