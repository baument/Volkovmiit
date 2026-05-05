#pragma once

#include <iostream>

using namespace std;

/**
 * @brief Класс "Точка"
 */
class Point
{
private:
    int x;
    int y;

    static int max_size_x;
    static int max_size_y;

    void checkPoint(void);
    bool checkX(const int x);
    bool checkY(const int y);

public:
    Point(const int x = 0, const int y = 0);

    Point(const Point& p);
    Point(Point&& p);

    int getX(void) const;
    int getY(void) const;

    static void getScreenDimensions(const int x, const int y);

    static int get_max_size_x(void);
    static int get_max_size_y(void);

    void operator=(const Point& other);
    void operator=(Point&& other);

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend ostream& operator<<(ostream& output, const Point& point);
    friend istream& operator>>(istream& input, Point& point);
};
