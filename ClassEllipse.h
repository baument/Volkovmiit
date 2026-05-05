#pragma once

#include "ClassShape.h"
#include "ClassPoint.h"

/**
 * @brief Класс "Овал"
 */
class Ellipse : public Shape
{
private:
    Point R;
    int a;
    int b;

    void CheckEllipse(void);

public:
    Ellipse(const Point R, const int a, const int b);

    Ellipse(const Ellipse& e);
    Ellipse(Ellipse&& e);

    Ellipse& operator=(const Ellipse& e);
    Ellipse& operator=(Ellipse&& e);

    void ToString(ostream& os) override;

    double getPerimeter() override;
    double getArea() override;
};
