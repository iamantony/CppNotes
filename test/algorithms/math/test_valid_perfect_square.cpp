#include <boost/test/unit_test.hpp>
#include "algorithms/math/valid_perfect_square.hpp"

BOOST_AUTO_TEST_SUITE(TestValidPerfectSquare)

BOOST_AUTO_TEST_CASE(test_vps_check)
{
    ValidPerfectSquare::Solution solution;
    BOOST_CHECK(false == solution.isPerfectSquare(0));
    BOOST_CHECK(true == solution.isPerfectSquare(1));
    BOOST_CHECK(false == solution.isPerfectSquare(2));
    BOOST_CHECK(false == solution.isPerfectSquare(3));
    BOOST_CHECK(true == solution.isPerfectSquare(4));
    BOOST_CHECK(false == solution.isPerfectSquare(7));
    BOOST_CHECK(true == solution.isPerfectSquare(9));
    BOOST_CHECK(false == solution.isPerfectSquare(15));
    BOOST_CHECK(true == solution.isPerfectSquare(16));
    BOOST_CHECK(true == solution.isPerfectSquare(256));
    BOOST_CHECK(false == solution.isPerfectSquare(257));
    BOOST_CHECK(false == solution.isPerfectSquare(125348));
}

BOOST_AUTO_TEST_SUITE_END()
