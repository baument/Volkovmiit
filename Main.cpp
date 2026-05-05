#include <cstdlib>
#include <iostream>

#include "../include/ClassEllipse.h"
#include "../include/ClassPoint.h"

using namespace std;

/**
 * @brief Считывает число, введённое с клавиатуры.
 * @return Считанное значение.
 */
int getNumber()
{
    int number = 0;

    cin >> number;

    if (cin.fail())
    {
        cerr << "Ошибка чтения" << endl;
        exit(1);
    }

    return number;
}

/**
 * @brief Задаёт разрешение экрана пользователя.
 */
void getDemension()
{
    cout << "Укажите размеры экрана в пикселях (x y): ";

    int x = getNumber();
    int y = getNumber();

    Point::getScreenDimensions(x, y);
}

/**
 * @brief Точка входа в программу.
 * @return Если программа выполнена корректно - 0, иначе 1.
 */
int main()
{
    system("chcp 1251");
    system("CLS");

    getDemension();

    cout << "Создание эллипса\n";
    cout << "Введите координаты центра (x y): ";

    Point center;
    cin >> center;

    cout << "Введите первую полуось: ";
    int a = getNumber();

    cout << "Введите вторую полуось: ";
    int b = getNumber();

    Ellipse ellipse(center, a, b);

    ellipse.ToString(cout);

    cout << "\nПлощадь: " << ellipse.getArea() << '\n';
    cout << "Периметр: " << ellipse.getPerimeter() << '\n';

    return 0;
}
