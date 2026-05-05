#define _USE_MATH_DEFINES
#include <gtest/gtest.h>

#include "../include/ClassEllipse.h"
#include "../include/ClassPoint.h"

#include <cmath>

/**
* @brief Тест операторов ==; !=; =; класса точки
*/
TEST(PointTest, Basic_Operators)
{
	Point::getScreenDimensions(1000, 1000);

	Point P1(10, 20);
	Point P2(10, 20);
	Point P3(20, 20);

	ASSERT_TRUE(P1 == P2);
	ASSERT_TRUE(P1 != P3);

	P1 = P3;
	ASSERT_TRUE(P1 == P3);
}

/**
* @brief Тест операторов <<; >>; класса точки
*/
TEST(PointTest, IO_Operators)
{
	Point::getScreenDimensions(1000, 1000);

	stringstream input("10 20");
	Point P;
	input >> P;

	ASSERT_EQ(P.getX(), 10);
	ASSERT_EQ(P.getY(), 20);

	stringstream output;
	output << P;
	ASSERT_EQ(output.str(), "(10, 20)");
}

/**
* @brief Тест функций задания экрана класса точка
*/
TEST(PointTest, ScreenDemension)
{
	Point::getScreenDimensions(100, 200);
	Point P;

	ASSERT_EQ(P.get_max_size_x(), 100);
	ASSERT_EQ(P.get_max_size_y(), 200);
}

/**
* @brief Тест функций класса эллипс
*/
TEST(EllipseTest, all_test)
{
	Point::getScreenDimensions(1000, 1000);

	const int a = 500;
	const int b = 400;
	Point R(500, 500);
	Ellipse E1(R, a, b);

	ASSERT_TRUE(fabs(E1.getPerimeter() - (2 * M_PI * sqrt((pow(a, 2) + pow(b, 2)) / 2))) <= DBL_EPSILON);
	ASSERT_TRUE(fabs(E1.getArea() - (M_PI * a * b)) <= DBL_EPSILON);

	stringstream output;
	E1.ToString(output);

	string result = output.str();

	ASSERT_NE(result.find("Информация об Эллипсе"), string::npos);
	ASSERT_NE(result.find("Координаты центра: O(500, 500)"), string::npos);
	ASSERT_NE(result.find("Большая полуось: 500"), string::npos);
	ASSERT_NE(result.find("Малая полуось: 400"), string::npos);
}