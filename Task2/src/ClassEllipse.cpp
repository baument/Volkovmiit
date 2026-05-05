#define _USE_MATH_DEFINES
#include "../include/ClassEllipse.h"
#include <cmath>

Ellipse::Ellipse(const Point R, const int a, const int b)
{
	this->R = R;
	this->a = a;
	this->b = b;

	CheckEllipse();
}

void Ellipse::CheckEllipse(void)
{
	if ((a == b) || (a <= 0) || (b <= 0))
	{
		cerr << "Error: Фигура не образует Эллипс" << endl;
		exit(1);
	}

	if (R.getX() - a < 0 || R.getX() + a > Point::get_max_size_x() || R.getY() - b < 0 || R.getY() + b > Point::get_max_size_y())
	{
		cerr << "Error: Фигура не образует Эллипс" << endl;
		exit(1);
	}
}

void Ellipse::ToString(ostream& os)
{
	os << "Информация об Эллипсе:" << endl << "Координаты центра: O(" << R.getX() << ", " << R.getY() << ")" << endl;
	if (a > b)
	{
		const int c = sqrt(pow(a, 2) - pow(b, 2));
		os << "Большая полуось: " << a << endl << "Малая полуось: " << b;
		os << endl << "Фокальное растояние: " << c;
		os << endl << "Эксцентриситет: " << (double)c / a;
		os << endl << "Координаты первого фокуса: F1(" << R.getX() - c << ", " << R.getY() << ")";
		os << endl << "Координаты второго фокуса: F2(" << R.getX() + c << ", " << R.getY() << ")";
	}
	else
	{
		const int c = sqrt(pow(b, 2) - pow(a, 2));
		os << "Большая полуось: " << b << endl << "Малая полуось: " << a;
		os << endl << "Фокальное растояние: " << c;
		os << endl << "Эксцентриситет: " << (double)c / b;
		os << endl << "Координаты первого фокуса: F1(" << R.getX() << ", " << R.getY() - c << ")";
		os << endl << "Координаты второго фокуса: F2(" << R.getX() << ", " << R.getY() + c << ")";
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