#ifndef LINAL_MATRIX_H
#define LINAL_MATRIX_H

#include <iostream>

using namespace std;

class Matrix {
public:

    Matrix();

    Matrix(int _m, int _n);

    Matrix(int _m, int _n, double **a);

    ~Matrix();

    int getStr() const;

    int getCol() const;

    double get(int i, int j) const;

    void set(int i, int j, double a);

    double det() const;

    Matrix &operator = (const Matrix &m2);

    bool operator==(const Matrix &m2) const;

    bool operator!=(const Matrix &m2) const;

    Matrix operator+(const Matrix &m2) const;

    Matrix operator-(const Matrix &m2) const;

    Matrix operator*(double a) const;

    Matrix operator*(const Matrix &m2) const;

private:
    int m, n;
    double **mas;
};

ostream &operator<<(ostream &os, const Matrix &M);

istream &operator>>(istream &is, Matrix &M);

#endif //LINAL_MATRIX_H
