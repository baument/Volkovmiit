#include "../include/ClassPoint.h"

#include <cstdlib>

int Point::max_size_x = 0;
int Point::max_size_y = 0;

void Point::checkPoint(void)
{
    if (!checkX(x) || !checkY(y))
    {
        cerr << "Точка лежит вне экрана" << endl;
        exit(1);
    }
}

bool Point::checkX(const int x)
{
    if (x < 0 || x > max_size_x)
    {
        return false;
    }

    return true;
}

bool Point::checkY(const int y)
{
    if (y < 0 || y > max_size_y)
    {
        return false;
    }

    return true;
}

Point::Point(const int x, const int y)
{
    this->x = x;
    this->y = y;

    checkPoint();
}

Point::Point(const Point& p)
{
    this->x = p.x;
    this->y = p.y;
}

Point::Point(Point&& p)
{
    this->x = p.x;
    this->y = p.y;
}

int Point::getX(void) const
{
    return x;
}

int Point::getY(void) const
{
    return y;
}

void Point::getScreenDimensions(const int x, const int y)
{
    if (x < 0 || y < 0)
    {
        cerr << "Недопустимые значения размера экрана" << endl;
        exit(1);
    }

    max_size_x = x;
    max_size_y = y;
}

int Point::get_max_size_x(void)
{
    return max_size_x;
}

int Point::get_max_size_y(void)
{
    return max_size_y;
}

void Point::operator=(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
}

void Point::operator=(Point&& other)
{
    this->x = other.x;
    this->y = other.y;
}

bool Point::operator==(const Point& other) const
{
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

ostream& operator<<(ostream& output, const Point& point)
{
    output << "(" << point.x << ", " << point.y << ")";
    return output;
}

istream& operator>>(istream& input, Point& point)
{
    int x = 0;
    int y = 0;

    input >> x >> y;

    if (input.fail())
    {
        cerr << "Ошибка чтения точки" << endl;
        exit(1);
    }

    point.x = x;
    point.y = y;

    point.checkPoint();

    return input;
}
