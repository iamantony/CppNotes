#include <boost/test/unit_test.hpp>
#include "algorithms/math/bitwise_operators.hpp"

BOOST_AUTO_TEST_SUITE(BitwiseOperations)

BOOST_AUTO_TEST_CASE(add)
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

BOOST_AUTO_TEST_CASE(abs) {
    BOOST_CHECK(0 == BitwiseOperators::BitwiseAbs(0));
    BOOST_CHECK(1 == BitwiseOperators::BitwiseAbs(1));
    BOOST_CHECK(1 == BitwiseOperators::BitwiseAbs(-1));
    BOOST_CHECK(16894 == BitwiseOperators::BitwiseAbs(16894));
    BOOST_CHECK(78953 == BitwiseOperators::BitwiseAbs(-78953));
}

BOOST_AUTO_TEST_SUITE_END()
