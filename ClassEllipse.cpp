#define _USE_MATH_DEFINES

#include "../include/ClassEllipse.h"

#include <cmath>
#include <cstdlib>

Ellipse::Ellipse(const Point R, const int a, const int b)
{
    this->R = R;
    this->a = a;
    this->b = b;

    CheckEllipse();
}

Ellipse::Ellipse(const Ellipse& e)
{
    this->R = e.R;
    this->a = e.a;
    this->b = e.b;
}

Ellipse::Ellipse(Ellipse&& e)
{
    this->R = e.R;
    this->a = e.a;
    this->b = e.b;
}

Ellipse& Ellipse::operator=(const Ellipse& e)
{
    if (this != &e)
    {
        this->R = e.R;
        this->a = e.a;
        this->b = e.b;
    }

    return *this;
}

Ellipse& Ellipse::operator=(Ellipse&& e)
{
    if (this != &e)
    {
        this->R = e.R;
        this->a = e.a;
        this->b = e.b;
    }

    return *this;
}

void Ellipse::CheckEllipse(void)
{
    if ((a == b) || (a <= 0) || (b <= 0))
    {
        cerr << "Error: Фигура не образует эллипс" << endl;
        exit(1);
    }

    if (R.getX() - a < 0 ||
        R.getX() + a > Point::get_max_size_x() ||
        R.getY() - b < 0 ||
        R.getY() + b > Point::get_max_size_y())
    {
        cerr << "Error: Эллипс выходит за границы экрана" << endl;
        exit(1);
    }
}

void Ellipse::ToString(ostream& os)
{
    os << "Информация об Эллипсе:" << endl;
    os << "Координаты центра: O(" << R.getX() << ", " << R.getY() << ")" << endl;

    if (a > b)
    {
        const int c = static_cast<int>(sqrt(pow(a, 2) - pow(b, 2)));

        os << "Большая полуось: " << a << endl;
        os << "Малая полуось: " << b << endl;
        os << "Фокальное расстояние: " << c << endl;
        os << "Эксцентриситет: " << static_cast<double>(c) / a << endl;
        os << "Координаты первого фокуса: F1(" << R.getX() - c << ", " << R.getY() << ")" << endl;
        os << "Координаты второго фокуса: F2(" << R.getX() + c << ", " << R.getY() << ")";
    }
    else
    {
        const int c = static_cast<int>(sqrt(pow(b, 2) - pow(a, 2)));

        os << "Большая полуось: " << b << endl;
        os << "Малая полуось: " << a << endl;
        os << "Фокальное расстояние: " << c << endl;
        os << "Эксцентриситет: " << static_cast<double>(c) / b << endl;
        os << "Координаты первого фокуса: F1(" << R.getX() << ", " << R.getY() - c << ")" << endl;
        os << "Координаты второго фокуса: F2(" << R.getX() << ", " << R.getY() + c << ")";
    }
}

double Ellipse::getPerimeter()
{
    return 2 * M_PI * sqrt((pow(a, 2) + pow(b, 2)) / 2);
}

double Ellipse::getArea()
{
    return M_PI * a * b;
}
