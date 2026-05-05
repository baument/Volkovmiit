#pragma once

#include <iostream>

using namespace std;

/**
 * @brief Класс "Точка".
 */
class Point
{
private:
    /**
     * @brief Координата точки по горизонтальной оси.
     */
    int x;

    /**
     * @brief Координата точки по вертикальной оси.
     */
    int y;

    /**
     * @brief Максимальное значение координаты X.
     */
    static int max_size_x;

    /**
     * @brief Максимальное значение координаты Y.
     */
    static int max_size_y;

    /**
     * @brief Проверяет, лежит ли точка в пределах экрана.
     */
    void checkPoint(void);

    /**
     * @brief Проверяет координату X.
     * @param x Проверяемая координата X.
     * @return true, если координата корректна, иначе false.
     */
    bool checkX(const int x);

    /**
     * @brief Проверяет координату Y.
     * @param y Проверяемая координата Y.
     * @return true, если координата корректна, иначе false.
     */
    bool checkY(const int y);

public:
    /**
     * @brief Создаёт экземпляр класса "Точка".
     * @param x Координата точки по горизонтальной оси. По умолчанию 0.
     * @param y Координата точки по вертикальной оси. По умолчанию 0.
     */
    Point(const int x = 0, const int y = 0);

    /**
     * @brief Создаёт экземпляр класса "Точка" копированием.
     * @param p Копируемая точка.
     */
    Point(const Point& p);

    /**
     * @brief Создаёт экземпляр класса "Точка" перемещением.
     * @param p Перемещаемая точка.
     */
    Point(Point&& p);

    /**
     * @brief Возвращает координату точки по горизонтальной оси.
     * @return Координата X.
     */
    int getX(void) const;

    /**
     * @brief Возвращает координату точки по вертикальной оси.
     * @return Координата Y.
     */
    int getY(void) const;

    /**
     * @brief Задаёт размеры экрана.
     * @param x Максимальное значение координаты X.
     * @param y Максимальное значение координаты Y.
     */
    static void getScreenDimensions(const int x, const int y);

    /**
     * @brief Возвращает максимальное значение координаты X.
     * @return Максимальное значение координаты X.
     */
    static int get_max_size_x(void);

    /**
     * @brief Возвращает максимальное значение координаты Y.
     * @return Максимальное значение координаты Y.
     */
    static int get_max_size_y(void);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Точка, значения которой копируются.
     */
    void operator=(const Point& other);

    /**
     * @brief Оператор присваивания перемещением.
     * @param other Точка, значения которой перемещаются.
     */
    void operator=(Point&& other);

    /**
     * @brief Сравнивает две точки на равенство.
     * @param other Точка для сравнения.
     * @return true, если точки равны, иначе false.
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Сравнивает две точки на неравенство.
     * @param other Точка для сравнения.
     * @return true, если точки не равны, иначе false.
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Выводит точку в поток.
     * @param output Поток вывода.
     * @param point Выводимая точка.
     * @return Поток вывода.
     */
    friend ostream& operator<<(ostream& output, const Point& point);

    /**
     * @brief Считывает точку из потока.
     * @param input Поток ввода.
     * @param point Считываемая точка.
     * @return Поток ввода.
     */
    friend istream& operator>>(istream& input, Point& point);
};
