#include "Class Square.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>

bool Square::eq(float a, float b) {
    const float EPS = 1e-6f;
    return fabs(a - b) < EPS;
}

float Square::distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Square::Square(float Ax, float Ay, float Bx, float By, float Cx, float Cy) {
    this->Ax = Ax;
    this->Ay = Ay;
    this->Bx = Bx;
    this->By = By;
    this->Cx = Cx;
    this->Cy = Cy;

    checkSquare();
}

void Square::checkSquare() {
    float D1 = distance(Ax, Ay, Bx, By);
    float D2 = distance(Ax, Ay, Cx, Cy);
    float D3 = distance(Bx, By, Cx, Cy);

    float ds[3] = {D1, D2, D3};
    std::sort(ds, ds + 3);

    if (eq(ds[0], 0)) {
        throw std::invalid_argument("Error: two points are the same");
    }

    if (!(eq(ds[0], ds[1]) && eq(ds[0] * ds[0] + ds[1] * ds[1], ds[2] * ds[2]))) {
        throw std::invalid_argument("Error: this isn't a square");
    }
}

float Square::perimeter() {
    float D1 = distance(Ax, Ay, Bx, By);
    float D2 = distance(Ax, Ay, Cx, Cy);
    float D3 = distance(Bx, By, Cx, Cy);

    float ds[3] = {D1, D2, D3};
    std::sort(ds, ds + 3);

    return 4 * ds[0];
}

float Square::area() {
    float D1 = distance(Ax, Ay, Bx, By);
    float D2 = distance(Ax, Ay, Cx, Cy);
    float D3 = distance(Bx, By, Cx, Cy);

    float ds[3] = {D1, D2, D3};
    std::sort(ds, ds + 3);

    return ds[0] * ds[0];
}
