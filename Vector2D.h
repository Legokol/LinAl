#ifndef LINAL_VECTOR2D_H
#define LINAL_VECTOR2D_H


class Vector2D {
public:
    Vector2D() : x(0), y(0) {}

    Vector2D(double _x, double _y) : x(_x), y(_y) {}

    ~Vector2D();

    double getX() const;

    double getY() const;

    void setX(double _x);

    void setY(double _y);

    bool operator==(const Vector2D &v2) const;

    bool operator!=(const Vector2D &v2) const;

    Vector2D operator+(const Vector2D &v2) const;

    Vector2D operator-(const Vector2D &v2) const;

    Vector2D operator*(const double a) const;

private:
    double x, y;
};




#endif //LINAL_VECTOR2D_H
