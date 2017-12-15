#ifndef TEST_SQUARE_ROOT_HPP
#define TEST_SQUARE_ROOT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/square_root.hpp"

BOOST_AUTO_TEST_CASE(test_sqroot_rough)
{
    BOOST_CHECK(-1 == SquareRoot::RoughSR(-1));
    BOOST_CHECK(-1 == SquareRoot::RoughSR(0));
    BOOST_CHECK(0 == SquareRoot::RoughSR(1));
    BOOST_CHECK(1 == SquareRoot::RoughSR(2));
    BOOST_CHECK(2 == SquareRoot::RoughSR(3));
    BOOST_CHECK(2 == SquareRoot::RoughSR(4));
    BOOST_CHECK(4 == SquareRoot::RoughSR(15));
    BOOST_CHECK(16 == SquareRoot::RoughSR(257));
    BOOST_CHECK(256 == SquareRoot::RoughSR(125348));
}

#endif // TEST_SQUARE_ROOT_HPP
