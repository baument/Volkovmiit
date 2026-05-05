#pragma once

class Square {
private:
    float Ax, Ay, Bx, By, Cx, Cy;

    static bool eq(float a, float b);
    float distance(float x1, float y1, float x2, float y2);
    void checkSquare();

public:
    Square(float Ax, float Ay, float Bx, float By, float Cx, float Cy);

    float perimeter();
    float area();
};
