#ifndef LINAL_VECTOR3D_H
#define LINAL_VECTOR3D_H

#include <iostream>

class Vector3D {
public:
    Vector3D() : x(0), y(0), z(0) {}

    Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    double getX() const;

    double getY() const;

    double getZ() const;

    void setX(double _x);

    void setY(double _y);

    void setZ(double _z);

    void rotateX(double angle); //Поворачивает вектор вокруг оси X (единичный вектор (1; 0; 0)) на угол angle, заданный в градусах

    void rotateY(double angle); //Поворачивает веткор вокруг оси Y (единичный вектор (0; 1; 0)) на угол angle, заданный в градусах

    void rotateZ(double angle); //Поворачивает веткор вокруг оси Z (единичный вектор (0; 0; 1)) на угол angle, заданный в градусах

    bool operator==(const Vector3D &v2) const;

    bool operator!=(const Vector3D &v2) const;

    Vector3D operator+(const Vector3D &v2) const;

    Vector3D operator-(const Vector3D &v2) const;

    Vector3D operator*(const double a) const;

    double operator*(const Vector3D &v2) const; //Скалярное произведение векторов

private:
    double x, y, z;
};

std::ostream &operator<<(std::ostream &os, const Vector3D &v);

std::istream &operator>>(std::istream &is, Vector3D &v);


#endif //LINAL_VECTOR3D_H
