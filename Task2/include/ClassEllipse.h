#pragma once

#include "ClassShape.h"
#include "ClassPoint.h"

/**
* @brief Класс "Овал"
*/
class Ellipse : public Shape
{
private:
	/**
	* @param R - точка-центр овала
	*/
	Point R;

	/**
	* @param a - первая полуось
	*/
	int a;

	/**
	* @param b - вторая полуось
	*/
	int b;

	/**
	* @brief Проверка на правильное задание Овала
	*/
	void CheckEllipse(void);

public:
	/**
	* @brief Базовый конструктор класса, задаёт овал через центр и две полуоси
	* @param R - точка-центр овала
	* @param a - первая полуось
	* @param b - вторая полуось
	*/
	Ellipse(const Point R, const int a, const int b);

	/**
	* @brief Виртуальная функция сериализации в строку для класса овал
	* @param os - поток вывода
	*/
	void ToString(ostream& os) override;

	/**
	* @brief Виртуальная функция расчёта периметра для класса овал
	* @return Периметр овала
	*/
	double getPerimeter() override;

	/**
	* @brief Виртуальная функция расчёта площади для класса овал
	* @return Площадь овала
	*/
	double getArea() override;
};