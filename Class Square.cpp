#include "Class Square.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <cfloat>

Square::Point::Point(const float x, const float y) {
    this->x = x;
    this->y = y;
}

bool Square::eq(const float a, const float b) {
    return fabs(a - b) < DBL_EPSILON;
}

float Square::distance(const Point first, const Point second) {
    return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

Square::Square(
    const float Ax,
    const float Ay,
    const float Bx,
    const float By,
    const float Cx,
    const float Cy
) : A(Ax, Ay), B(Bx, By), C(Cx, Cy) {
    checkSquare();
}

void Square::checkSquare() const {
    const float D1 = distance(A, B);
    const float D2 = distance(A, C);
    const float D3 = distance(B, C);

    float ds[3] = {D1, D2, D3};
    std::sort(ds, ds + 3);

    if (eq(ds[0], 0)) {
        throw std::invalid_argument("Error: two points are the same");
    }

    if (!(eq(ds[0], ds[1]) && eq(ds[0] * ds[0] + ds[1] * ds[1], ds[2] * ds[2]))) {
        throw std::invalid_argument("Error: this isn't a square");
    }
}

float Square::perimeter() const {
    const float D1 = distance(A, B);
    const float D2 = distance(A, C);
    const float D3 = distance(B, C);

    float ds[3] = {D1, D2, D3};
    std::sort(ds, ds + 3);

    return 4 * ds[0];
}

float Square::area() const {
    const float D1 = distance(A, B);
    const float D2 = distance(A, C);
    const float D3 = distance(B, C);

    float ds[3] = {D1, D2, D3};
    std::sort(ds, ds + 3);

    return ds[0] * ds[0];
}
