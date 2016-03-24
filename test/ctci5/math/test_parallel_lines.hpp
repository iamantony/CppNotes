#ifndef TEST_PARALLEL_LINES_HPP_
#define TEST_PARALLEL_LINES_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <vector>

#include "ctci5/math/parallel_lines.hpp"

BOOST_AUTO_TEST_CASE(test_parallel_lines_dots)
{
    Point dot;
    Line first(dot, dot);
    Line second(dot, dot);

    BOOST_CHECK(AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(test_parallel_lines_line_and_dot)
{
    Point dot;
    Line first(dot, dot);
    Point x(1, 1), y(2, 2);
    Line second(x, y);

    BOOST_CHECK(false == AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(test_parallel_lines_same_lines)
{
    Point x(1, 1), y(2, 2);
    Line first(x, y);
    Line second(x, y);

    BOOST_CHECK(AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(test_parallel_lines_parallel)
{
    Point x1(-12, 0), y1(0, 8);
    Line first(x1, y1);

    Point x2(0, -12), y2(18, 0);
    Line second(x2, y2);

    BOOST_CHECK(AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(test_parallel_lines_not_parallel)
{
    Point x1(-12, 0), y1(0, 8);
    Line first(x1, y1);

    Point x2(0, -12), y2(18, 5);
    Line second(x2, y2);

    BOOST_CHECK(false == AreLinesParallel(first, second));
}


#endif /* TEST_PARALLEL_LINES_HPP_ */
