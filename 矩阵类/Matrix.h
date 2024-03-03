//#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "Row.h"

class Matrix {
public:
    Matrix(const std::vector<std::vector<int>>& elements);
    Matrix(int _h, int _l);
    Matrix(const Matrix& A);
    Matrix();

    Matrix multiply(const Matrix& other) const;
    Matrix add(const Matrix& other) const;
    Matrix subtraction(const Matrix& other) const;

    void display();

    int h;
    int l;
    std::vector<Row>* row;
};

#endif // MATRIX_H
