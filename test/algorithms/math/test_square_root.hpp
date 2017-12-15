#ifndef TEST_SQUARE_ROOT_HPP
#define TEST_SQUARE_ROOT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/square_root.hpp"
#include "common/equality.hpp"

BOOST_AUTO_TEST_CASE(test_sqroot_rough)
{
    BOOST_CHECK(-1 == SquareRoot::RoughSR(-1));
    BOOST_CHECK(-1 == SquareRoot::RoughSR(0));
    BOOST_CHECK(1 == SquareRoot::RoughSR(1));
    BOOST_CHECK(1 == SquareRoot::RoughSR(2));
    BOOST_CHECK(2 == SquareRoot::RoughSR(3));
    BOOST_CHECK(2 == SquareRoot::RoughSR(4));
    BOOST_CHECK(4 == SquareRoot::RoughSR(15));
    BOOST_CHECK(16 == SquareRoot::RoughSR(257));
    BOOST_CHECK(256 == SquareRoot::RoughSR(125348));
}

BOOST_AUTO_TEST_CASE(test_sqroot_babylonial)
{
    const double epsilon = 0.0001;
    BOOST_CHECK(equalDoubles(0.0, SquareRoot::BabylonialSR(-1, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(0.0, SquareRoot::BabylonialSR(0, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(1.0, SquareRoot::BabylonialSR(1, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(1.4142, SquareRoot::BabylonialSR(2, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(1.7320, SquareRoot::BabylonialSR(3, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(2.0, SquareRoot::BabylonialSR(4, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(3.8729, SquareRoot::BabylonialSR(15, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(16.0312, SquareRoot::BabylonialSR(257, epsilon), epsilon));
    BOOST_CHECK(equalDoubles(354.0451, SquareRoot::BabylonialSR(125348, epsilon), epsilon));
}

BOOST_AUTO_TEST_CASE(test_sqroot_with_rounding)
{
    SquareRoot::Solution solution;
    BOOST_CHECK(0 == solution.mySqrt(0));
    BOOST_CHECK(1 == solution.mySqrt(1));
    BOOST_CHECK(1 == solution.mySqrt(2));
    BOOST_CHECK(1 == solution.mySqrt(3));
    BOOST_CHECK(2 == solution.mySqrt(4));
    BOOST_CHECK(3 == solution.mySqrt(15));
    BOOST_CHECK(16 == solution.mySqrt(257));
    BOOST_CHECK(354 == solution.mySqrt(125348));
}

#endif // TEST_SQUARE_ROOT_HPP
