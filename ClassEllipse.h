#pragma once

#include "ClassShape.h"
#include "ClassPoint.h"

/**
 * @brief Класс "Овал".
 */
class Ellipse : public Shape
{
private:
    /**
     * @brief Центр овала.
     */
    Point R;

    /**
     * @brief Первая полуось овала.
     */
    int a;

    /**
     * @brief Вторая полуось овала.
     */
    int b;

    /**
     * @brief Проверяет корректность задания овала.
     */
    void CheckEllipse(void);

public:
    /**
     * @brief Создаёт экземпляр класса "Овал" через центр и две полуоси.
     * @param R Точка-центр овала.
     * @param a Первая полуось овала.
     * @param b Вторая полуось овала.
     */
    Ellipse(const Point R, const int a, const int b);

    /**
     * @brief Создаёт экземпляр класса "Овал" копированием.
     * @param e Копируемый овал.
     */
    Ellipse(const Ellipse& e);

    /**
     * @brief Создаёт экземпляр класса "Овал" перемещением.
     * @param e Перемещаемый овал.
     */
    Ellipse(Ellipse&& e);

    /**
     * @brief Оператор присваивания копированием.
     * @param e Овал, значения которого копируются.
     * @return Текущий объект.
     */
    Ellipse& operator=(const Ellipse& e);

    /**
     * @brief Оператор присваивания перемещением.
     * @param e Овал, значения которого перемещаются.
     * @return Текущий объект.
     */
    Ellipse& operator=(Ellipse&& e);

    /**
     * @brief Выводит информацию об овале в поток.
     * @param os Поток вывода.
     */
    void ToString(ostream& os) override;

    /**
     * @brief Вычисляет периметр овала.
     * @return Периметр овала.
     */
    double getPerimeter() override;

    /**
     * @brief Вычисляет площадь овала.
     * @return Площадь овала.
     */
    double getArea() override;
};
