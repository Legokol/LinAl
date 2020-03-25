#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() : m(0), n(0), mas(nullptr) {}

Matrix::Matrix(const Matrix &M) : Matrix(M.getCol(), M.getStr()) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mas[i][j] = M.get(i, j);
}

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
    if (mas != nullptr)
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

Matrix &Matrix::operator+=(const Matrix &m2) {
    *this = *this + m2;
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m2) {
    *this = *this - m2;
    return *this;
}

Matrix &Matrix::operator*=(double a) {
    *this = *this *a;
    return *this;
}

double Matrix::det() const {
    if (m != n) {
        cout << "Can't calculate determinant for non-quadratic matrix." << endl;
        return 0;
    }
    if (m == 1)
        return mas[0][0];
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
        cout << "Can't sum matrices of different size." << endl;
        return Matrix();
    }
    Matrix M(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M.set(i, j, mas[i][j] + m2.get(i, j));
    return Matrix(M);
}

Matrix Matrix::operator-(const Matrix &m2) const {
    if (m != m2.getStr() || n != m2.getCol()) {
        cout << "Can't subtract matrices of different size." << endl;
        return Matrix();
    }
    Matrix M(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M.set(i, j, mas[i][j] - m2.get(i, j));
    return Matrix(M);
}

Matrix Matrix::operator*(double a) const {
    Matrix M(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M.set(i, j, mas[i][j] * a);
    return Matrix(M);
}

Matrix Matrix::operator*(const Matrix &m2) const {
    if (n != m2.getStr()) {
        cout << "Can't multiply matrices. Wrong size." << endl;
        return Matrix();
    }
    Matrix M(m, m2.getCol());
    double a = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m2.getCol(); j++) {
            for (int k = 0; k < n; k++)
                a += mas[i][k] * m2.get(k, j);
            M.set(i, j, a);
            a = 0;
        }
    return Matrix(M);
}

Matrix operator*(double a, Matrix &M) {
    return M * a;
}


ostream &operator<<(ostream &os, const Matrix &M) {
    int m = M.getStr(), n = M.getCol();
    os << '{';
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