#include <boost/test/unit_test.hpp>
#include "algorithms/math/parallel_lines.hpp"

BOOST_AUTO_TEST_SUITE(CheckIfParallelLines)

BOOST_AUTO_TEST_CASE(dots)
{
    Point dot;
    Line first(dot, dot);
    Line second(dot, dot);

    BOOST_CHECK(AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(line_and_dot)
{
    Point dot;
    Line first(dot, dot);
    Point x(1, 1), y(2, 2);
    Line second(x, y);

    BOOST_CHECK(false == AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(same_lines)
{
    Point x(1, 1), y(2, 2);
    Line first(x, y);
    Line second(x, y);

    BOOST_CHECK(AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(parallel)
{
    Point x1(-12, 0), y1(0, 8);
    Line first(x1, y1);

    Point x2(0, -12), y2(18, 0);
    Line second(x2, y2);

    BOOST_CHECK(AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_CASE(not_parallel)
{
    Point x1(-12, 0), y1(0, 8);
    Line first(x1, y1);

    Point x2(0, -12), y2(18, 5);
    Line second(x2, y2);

    BOOST_CHECK(false == AreLinesParallel(first, second));
}

BOOST_AUTO_TEST_SUITE_END()
