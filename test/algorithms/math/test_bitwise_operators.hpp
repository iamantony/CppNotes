#ifndef TEST_BITWISE_OPERATORS_HPP
#define TEST_BITWISE_OPERATORS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/bitwise_operators.hpp"

BOOST_AUTO_TEST_CASE(test_bitop_add)
{
    BOOST_CHECK(0 == BitwiseOperators::BitwiseAdd(0, 0));
    BOOST_CHECK(0 == BitwiseOperators::BitwiseAddRecursive(0, 0));

    BOOST_CHECK(1 == BitwiseOperators::BitwiseAdd(1, 0));
    BOOST_CHECK(1 == BitwiseOperators::BitwiseAddRecursive(1, 0));

    BOOST_CHECK(1 == BitwiseOperators::BitwiseAdd(0, 1));
    BOOST_CHECK(1 == BitwiseOperators::BitwiseAddRecursive(0, 1));

    BOOST_CHECK(2 == BitwiseOperators::BitwiseAdd(1, 1));
    BOOST_CHECK(2 == BitwiseOperators::BitwiseAddRecursive(1, 1));

    BOOST_CHECK(5 == BitwiseOperators::BitwiseAdd(2, 3));
    BOOST_CHECK(5 == BitwiseOperators::BitwiseAddRecursive(2, 3));
}

#endif // TEST_BITWISE_OPERATORS_HPP
