#pragma once
#include <iostream>
#include <string>  

using namespace std;

/**
* @brief Абстрактный класс "Фигура"
*/
class Shape
{
public:
	/**
	* @brief Виртуальная функция сериализации в строку
	*/
	virtual void ToString(ostream& os) = 0;

	/**
	* @brief Виртуальная функция расчёта периметра
	*/
	virtual double getPerimeter() = 0;

	/**
	* @brief Виртуальная функция расчёта площади
	*/
	virtual double getArea() = 0;

	/**
	* @brief Виртуальный деструктор по-умолчанию
	*/
	virtual ~Shape() = default;
};