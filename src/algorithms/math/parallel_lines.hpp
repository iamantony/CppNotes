#ifndef PARALLEL_LINES_HPP_
#define PARALLEL_LINES_HPP_

#include <cmath>
#include <limits>
#include <iostream>

#define PI 3.14159265

// Given two lines on a Cartesian plane, determine whether the two lines
// would intersect

// http://www.wikihow.com/Find-the-Slope-of-a-Line
// http://matematikalegko.ru/koordinatnaya-ploskost/uglovoj-koefficient-pryamoj-i-ne-tolko.html

class Point
{
public:
    explicit Point(double xValue = 0.0, double yValue = 0.0) :
        x(xValue), y(yValue) {}

    friend bool operator==(const Point& left, const Point& right);

    double x;
    double y;
};

bool operator==(const Point& left, const Point& right)
{
    if (std::abs(left.x - right.x) <= std::numeric_limits<double>::epsilon() &&
        std::abs(left.y - right.y) <= std::numeric_limits<double>::epsilon())
    {
        return true;
    }

    return false;
}

class Line
{
public:
    explicit Line(const Point& first, Point& second) :
            p1(first), p2(second) {}

    double GetAngle() const
    {
        // Check if points are the same
        if (p1 == p2)
        {
            return 0.0;
        }

        // Check if X coordinates are equal
        if (std::abs(p1.x - p2.x) <= std::numeric_limits<double>::epsilon())
        {
            return 0.0;
        }

        double tang = (p2.y - p1.y) / (p2.x - p1.x);
        return std::atan(tang) * 180 / PI;
    }

private:
    Point p1;
    Point p2;
};

bool AreLinesParallel(const Line& first, const Line& second)
{
    double firstAngle = first.GetAngle();
    double secondAngle = second.GetAngle();
    double diff = std::abs(firstAngle - secondAngle);
    if (std::numeric_limits<double>::epsilon() < diff &&
            std::numeric_limits<double>::epsilon() < (180.0 -diff))
    {
        return false;
    }

    return true;
}

#endif /* PARALLEL_LINES_HPP_ */
