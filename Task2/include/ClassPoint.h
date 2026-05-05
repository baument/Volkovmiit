#pragma once

#include <iostream>

using namespace std;

/**
* @brief Класс "Точка"
*/
class Point
{
private:
	/**
	* @param x - координата точки по горизонтальной оси
	*/
	int x;

	/**
	* @param y - координата точки по вертикальной оси
	*/
	int y;

	/**
	* @param max_size_x - максимальное значение которое может принимать параметр x
	*/
	static int max_size_x;

	/**
	* @param max_size_y - максимальное значение которое может принимать параметр y
	*/
	static int max_size_y;

	/**
	* @brief Функция проверки для точки
	*/
	void checkPoint(void);

	/**
	* @brief Функция координаты x
	* @param x - проверяемая координата
	* @return Если проверка пройдена - 1, иначе 0
	*/
	bool checkX(const int x);

	/**
	* @brief Функция координаты y
	* @param y - проверяемая координата
	* @return Если проверка пройдена - 1, иначе 0
	*/
	bool checkY(const int y);

public:
	/**
	* @brief Базовый конструктор класса, меняет значения x и y на указанные пользователем
	* @param x - передаваемое значение по оси x (по умолчанию 0)
	* @param y - передаваемое значение по оси y (по умолчанию 0)
	*/
	Point(const int x = 0, const int y = 0);

	/**
	* @brief Получает значение по оси x у конкретной точки
	* @return Значение по оси x
	*/
	int getX(void) const;

	/**
	* @brief Получает значение по оси y у конкретной точки
	* @return Значение по оси y
	*/
	int getY(void) const;

	/**
	* @brief Задаёт максимальные значения для x и y
	* @param x - максимальное значение по x
	* @param y - максимальное значение по y
	*/
	static void getScreenDimensions(const int x, const int y);

	/**
	* @brief Получает максимальное значение по x
	* @return Максимальное значение по x
	*/
	static int get_max_size_x(void);

	/**
	* @brief Получает максимальное значение по y
	* @return Максимальное значение по y
	*/
	static int get_max_size_y(void);

	/**
	* @brief Оператор приравнивания, присваивает значение координат другой точке
	* @param other - точка, на чьи значения будет происходить замена
	*/
	void operator = (const Point& other);

	/**
	* @brief Оператор равенства, точки считаются равными, если их координаты попарно равны
	* @param other - точка, с которой происходит сравнение
	*/
	bool operator == (const Point& other) const;

	/**
	* @brief Оператор равенства, точки считаются не равными, если их координаты попарно не равны
	* @param other - точка, с которой происходит сравнение
	*/
	bool operator != (const Point& other) const;

	/**
	* @brief Оператор вывода для класса точка
	* @param output - ссылка на поток вывода
	* @param point - ссылка на выводимую точку
	* @return Координаты точки в формате (x,y)
	*/
	friend ostream& operator << (ostream& output, const Point& point);

	/**
	* @brief Оператор ввода для класса точка
	* @param input - ссылка на поток ввода
	* @param point - ссылка на вводимую точку
	*/
	friend istream& operator >> (istream& input, Point& point);
};