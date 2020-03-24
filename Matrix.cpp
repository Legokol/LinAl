#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() : Matrix(0, 0) {}

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

Matrix &Matrix::operator=(const Matrix &m2) {
    delete[] mas;
    m = m2.getStr();
    n = m2.getCol();
    mas = new double *[m];
    for (int i = 0; i < m; i++) {
        mas[i] = new double[n];
        for (int j = 0; j < n; j++)
            mas[i][j] = m2.get(i, j);
    }
    return *this;
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

Matrix Matrix::operator+(const Matrix &m2) const {
    if (m != m2.getStr() || n != m2.getCol()) {
        cout << "Can't sum matrices of different size" << endl;
        return Matrix();
    }
    Matrix M(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M.set(i, j, mas[i][j] + m2.get(i, j));
    return M;
}

ostream &operator<<(ostream &os, const Matrix &M) {
    int m = M.getStr(), n = M.getCol();
    os  << '{';
    for (int i = 0; i < m; i++) {
        cout << '(';
        for (int j = 0; j < n - 1; j++)
            cout << M.get(i, j) << "; ";
        if (i != m - 1)
            cout << M.get(i, n - 1) << ')' << endl;
        else
            cout << M.get(i, n - 1) << ")}" << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix &M) {
    int m = M.getStr(), n = M.getCol();
    double a;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            is >> a;
            M.set(i, j, a);
        }
    return is;
}