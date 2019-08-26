#ifndef TEST_GREATES_COMMON_DIVISOR_HPP
#define TEST_GREATES_COMMON_DIVISOR_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/greatest_common_divisor.hpp"

BOOST_AUTO_TEST_CASE(test_gcd_numbers)
{
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(1, 1) == 1);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(5, 1) == 1);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(5, 15) == 5);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(18, 35) == 1);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(28851538, 1183019) == 17657);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(3918848, 1653264) == 61232);
}

#endif // TEST_GREATES_COMMON_DIVISOR_HPP

