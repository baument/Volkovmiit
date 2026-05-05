#pragma once

class Square {
private:
    struct Point {
        float x;
        float y;

        Point(const float x, const float y);
    };

    Point A;
    Point B;
    Point C;

    static bool eq(const float a, const float b);
    static float distance(const Point first, const Point second);

    void checkSquare() const;

public:
    Square(
        const float Ax,
        const float Ay,
        const float Bx,
        const float By,
        const float Cx,
        const float Cy
    );

    float perimeter() const;
    float area() const;
};
