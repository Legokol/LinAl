#include <iostream>
#include "Vector2D.h"

using namespace std;

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

void Vector2D::setX(double _x) {
    x = _x;
}

void Vector2D::setY(double _y) {
    y = _y;
}

bool Vector2D::operator==(const Vector2D &v2) const {
    return x == v2.getX() && y == v2.getY();
}

bool Vector2D::operator!=(const Vector2D &v2) const {
    return !(*this == v2);
}

Vector2D Vector2D::operator+(const Vector2D &v2) const {
    return Vector2D(x + v2.getX(), y + v2.getY());
}

Vector2D Vector2D::operator-(const Vector2D &v2) const {
    return Vector2D(x + v2.getX(), y + v2.getY());
}

Vector2D Vector2D::operator*(const double a) const {
    return Vector2D(getX() * a, getY() * a);
}

Vector2D operator*(double a, const Vector2D &v) {
    return v * a;
}

ostream &operator<<(ostream &os, const Vector2D &v) {
    os << '(' << v.getX() << "; " << v.getY() << ')';
    return os;
}

istream &operator>>(istream &is, Vector2D &v) {
    int _x, _y;
    is >> _x >> _y;
    v.setX(_x);
    v.setY(_y);
    return is;
}