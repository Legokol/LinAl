#include <iostream>
#include <cmath>
#include "Vector3D.h"

using namespace std;

double Vector3D::getX() const {
    return x;
}

double Vector3D::getY() const {
    return y;
}

double Vector3D::getZ() const {
    return z;
}

void Vector3D::setX(double _x) {
    x = _x;
}

void Vector3D::setY(double _y) {
    y = _y;
}

void Vector3D::setZ(double _z) {
    z = _z;
}

void Vector3D::rotateX(double angle) {
    angle = angle * 3.14 / 180;
    double _y = getY(), _z = getZ();
    setY(_y * cos(angle) + _z * sin(angle));
    setZ(-_y * sin(angle) + _z * cos(angle));
}

void Vector3D::rotateY(double angle) {
    angle = angle * 3.14 / 180;
    double _z = getZ(), _x = getX();
    setZ(_z * cos(angle) + _x * sin(angle));
    setX(-_z * sin(angle) + _x * cos(angle));
}

void Vector3D::rotateZ(double angle) {
    angle = angle * 3.14 / 180;
    double _x = getX(), _y = getY();
    setX(_x * cos(angle) + _y * sin(angle));
    setY(-_x * sin(angle) + _y * cos(angle));
}

Vector3D & Vector3D::operator=(const Vector3D &V) {
    x = getX();
    y = getY();
    z = getZ();
    return (*this);
}

bool Vector3D::operator==(const Vector3D &v2) const {
    return x == v2.getX() && y == v2.getY();
}

bool Vector3D::operator!=(const Vector3D &v2) const {
    return !(*this == v2);
}

Vector3D Vector3D::operator+(const Vector3D &v2) const {
    return Vector3D(getX() + v2.getX(), getY() + v2.getY(), getZ() + v2.getZ());
}

Vector3D Vector3D::operator-(const Vector3D &v2) const {
    return Vector3D(getX() - v2.getX(), getY() - v2.getY(), getZ() - v2.getZ());
}

Vector3D Vector3D::operator*(const double a) const {
    return Vector3D(getX() * a, getY() * a, getZ() * a);
}

double Vector3D::operator*(const Vector3D &v2) const {
    return getX() * v2.getX() + getY() * v2.getY() + getZ() * v2.getZ();
}

Vector3D operator*(double a, const Vector3D &v) {
    return v * a;
}

ostream &operator<<(ostream &os, const Vector3D &v) {
    os << '(' << v.getX() << "; " << v.getY() << "; " << v.getZ() << ')';
    return os;
}

istream &operator>>(istream &is, Vector3D &v) {
    double _x, _y, _z;
    is >> _x >> _y >> _z;
    v.setX(_x);
    v.setY(_y);
    v.setZ(_z);
    return is;
}