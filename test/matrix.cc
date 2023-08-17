#include <assert.h>
#include <iostream>
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

void add() {
    Matrix m = zeros(3, 2);
    Matrix p({{1, 2}, {7, 2}, {6, 6}});

    Matrix mp = m + p;
    assert(mp == p);

    Matrix q({{0, 1}, {2, 3}, {2, 1}});
    Matrix pq({{1, 3}, {9, 5}, {8, 7}});

    assert(p + q == pq);
}

void inplace_add() {
    Matrix q({{0, 1}, {2, 3}, {2, 1}});
    Matrix p({{1, 2}, {7, 2}, {6, 6}});
    Matrix pq({{1, 3}, {9, 5}, {8, 7}});

    p += q;

    assert(p == pq);
}

void multiply() {
    Matrix p({{1, 2, 1}, {7, 2, 1}, {6, 6, 1}});
    Matrix q({{0, 1}, {2, 3}, {2, 1}});
    Matrix pq({{6, 8}, {6, 14}, {14, 25}});

    assert(pq == p * q);
}

void multiply_scalar() {
    Matrix p({{1, 2, 1}, {7, 2, 1}, {6, 6, 1}});
    Matrix p3({{3, 6, 3}, {21, 6, 3}, {18, 18, 3}});
    assert(p * 3 == p3);
}

void clone() {
    Matrix p({{1, 2, 1}, {7, 2, 1}, {6, 6, 1}});
    Matrix q = p.clone();
    assert(p == q);
}


int main() {
    construct();
    construct_il();
    clone();
    add();
    inplace_add();
    multiply();
    multiply_scalar();
}