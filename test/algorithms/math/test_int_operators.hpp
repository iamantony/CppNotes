#ifndef TEST_INT_OPERATORS_HPP_
#define TEST_INT_OPERATORS_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/math/int_operators.hpp"

BOOST_AUTO_TEST_CASE(test_int_oper_negate)
{
    BOOST_CHECK(0 == Negate(0));
    BOOST_CHECK(-4 == Negate(4));
    BOOST_CHECK(105 == Negate(-105));
}

BOOST_AUTO_TEST_CASE(test_int_oper_abs)
{
    BOOST_CHECK(0 == ABSInt(0));
    BOOST_CHECK(4 == ABSInt(4));
    BOOST_CHECK(105 == ABSInt(-105));
}

BOOST_AUTO_TEST_CASE(test_int_oper_subtract)
{
    BOOST_CHECK(0 == Subtract(0, 0));
    BOOST_CHECK(10 == Subtract(10, 0));
    BOOST_CHECK(60 == Subtract(0, -60));
    BOOST_CHECK(0 == Subtract(10, 10));
    BOOST_CHECK(50 == Subtract(58, 8));
    BOOST_CHECK(-8 == Subtract(12, 20));
    BOOST_CHECK(14 == Subtract(12, -2));
    BOOST_CHECK(-5 == Subtract(-7, -2));
    BOOST_CHECK(0 == Subtract(-7, -7));
    BOOST_CHECK(-14 == Subtract(-7, 7));
}

BOOST_AUTO_TEST_CASE(test_int_oper_multiply)
{
    BOOST_CHECK(0 == Multiply(0, 0));
    BOOST_CHECK(0 == Multiply(10, 0));
    BOOST_CHECK(0 == Multiply(0, -60));
    BOOST_CHECK(100 == Multiply(10, 10));
    BOOST_CHECK(464 == Multiply(58, 8));
    BOOST_CHECK(-24 == Multiply(12, -2));
    BOOST_CHECK(14 == Multiply(-7, -2));
    BOOST_CHECK(-49 == Multiply(-7, 7));
}

BOOST_AUTO_TEST_CASE(test_int_oper_divide)
{
    BOOST_CHECK(0 == Divide(0, 0));
    BOOST_CHECK(0 == Divide(10, 0));
    BOOST_CHECK(0 == Divide(0, -60));
    BOOST_CHECK(1 == Divide(10, 10));
    BOOST_CHECK(8 == Divide(64, 8));
    BOOST_CHECK(7 == Divide(58, 8));
    BOOST_CHECK(-6 == Divide(12, -2));
    BOOST_CHECK(3 == Divide(-7, -2));
    BOOST_CHECK(-1 == Divide(-7, 7));
}

#endif /* TEST_INT_OPERATORS_HPP_ */
