#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int _m, int _n) : m(_m), n(_n) {
    mas = new double *[m];
    for (int i = 0; i < m; i++)
        mas[i] = new double[n];
}

Matrix::Matrix(int _m, int _n, double **a) : Matrix(_m, _n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mas[i][j] = a[i][j];
}

Matrix::~Matrix() {
    delete[] mas;
}

int Matrix::getStr() const {
    return m;
}

int Matrix::getCol() const {
    return n;
}

double Matrix::get(int i, int j) const {
    return mas[i][j];
}

void Matrix::set(int i, int j, double a) {
    if (i >= m || j >= n) {
        cout << "Can't set. Element out of range" << endl;
        return;
    }
    mas[i][j] = a;
}

bool Matrix::operator==(const Matrix &m2) const {
    if (m != m2.getStr() || n != m2.getCol())
        return false;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mas[i][j] != m2.get(i, j))
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix &m2) const {
    return !(*this == m2);
}
