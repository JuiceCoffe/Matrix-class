#include <iostream>
#include "Matrix.h"

Matrix getMatrix();
char duru(Matrix& Matrix_A, Matrix& Matrix_B);
void Calculation_and_show(Matrix& Matrix_A, Matrix& Matrix_B, char Operator);
void run();

int main() {
    run();
    return 0;
}

Matrix getMatrix() {
    int h, l;
    std::cout << "输入行列数" << std::endl;
    std::cin >> h >> l;

    std::vector<std::vector<int>> temp(h, std::vector<int>(l));

    std::cout << "输入元素" << std::endl;
    for (int H = 0; H < h; H++) {
        for (int L = 0; L < l; L++) {
            std::cin >> temp[H][L];
        }
    }
    std::cout << std::endl;
    Matrix rst(temp);
    return rst;
}

char duru(Matrix& Matrix_A, Matrix& Matrix_B) {
    std::cout << "Please enter Matrix A:" << std::endl;
    Matrix_A = getMatrix();
    std::cout << "Please enter the operation" << std::endl;
    char Operator;
    std::cin >> Operator;
    std::cout << std::endl;
    std::cout << "Please enter Matrix B:" << std::endl;
    Matrix_B = getMatrix();
    return Operator;
}

void Calculation_and_show(Matrix& Matrix_A, Matrix& Matrix_B, char Operator) {
    switch (Operator) {
    case'*':
        (Matrix_A.multiply(Matrix_B)).display();
        break;
    case'+':
        (Matrix_A.add(Matrix_B)).display();
        break;
    case'-':
        (Matrix_A.subtraction(Matrix_B)).display();
        break;
    }
}

void run() {
    Matrix Matrix_A, Matrix_B;
    char Operator = duru(Matrix_A, Matrix_B);
    Calculation_and_show(Matrix_A, Matrix_B, Operator);
}
