#include "Matrix.h"
#include <iostream>

Matrix::Matrix() : h(0), l(0), row(nullptr) {}

Matrix::Matrix(const std::vector<std::vector<int>>& elements) : h(elements.size()), l(elements[0].size()), row(new std::vector<Row>(h)) {
    for (int i = 0; i < h; ++i) {
        (*row)[i].column = elements[i];
    }
}

Matrix::Matrix(int _h, int _l) : h(_h), l(_l), row(new std::vector<Row>(_h)) {
    for (int i = 0; i < _h; ++i) {
        (*row)[i].column.resize(_l);
    }
}

Matrix::Matrix(const Matrix& A) : h(A.h), l(A.l), row(new std::vector<Row>(*A.row)) {}

Matrix Matrix::multiply(const Matrix& other) const {
    if (l != other.h) {
        std::cout << "行列数不匹配\n";
        exit(0);
    }

    Matrix result(h, other.l);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < other.l; ++j) {
            int sum = 0;
            for (int k = 0; k < l; ++k) {
                sum += (*row)[i].column[k] * (*other.row)[k].column[j];
            }
            (*result.row)[i].column[j] = sum;
        }
    }
    return result;
}

Matrix Matrix::add(const Matrix& other) const {
    if (h != other.h || l != other.l) {
        std::cout << "行列数不匹配" << std::endl;
        exit(0);
    }

    Matrix result(h, l);
    for (int H = 0; H < h; H++) {
        for (int L = 0; L < l; L++) {
            (*result.row)[H].column[L] = (*(*this).row)[H].column[L] + (*other.row)[H].column[L];
        }
    }
    return result;
}

Matrix Matrix::subtraction(const Matrix& other) const {
    if (h != other.h || l != other.l) {
        std::cout << "行列数不匹配" << std::endl;
        exit(0);
    }

    Matrix result(h, l);
    for (int H = 0; H < h; H++) {
        for (int L = 0; L < l; L++) {
            (*result.row)[H].column[L] = (*(*this).row)[H].column[L] - (*other.row)[H].column[L];
        }
    }
    return result;
}

void Matrix::display() {
    for (int H = 0; H < h; H++) {
        for (int L = 0; L < l; L++) {
            std::cout << (*row)[H].column[L] << "\t";
        }
        std::cout << std::endl;
    }
}
