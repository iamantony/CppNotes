#include <boost/test/unit_test.hpp>
#include "algorithms/math/greatest_common_divisor.hpp"

BOOST_AUTO_TEST_SUITE(TestGreatestCommonDivisor)

BOOST_AUTO_TEST_CASE(numbers)
{
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(1, 1) == 1);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(5, 1) == 1);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(5, 15) == 5);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(18, 35) == 1);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(28851538, 1183019) == 17657);
    BOOST_CHECK(Algo::Math::GreatestCommonDivisor::Calc(3918848, 1653264) == 61232);
}

BOOST_AUTO_TEST_SUITE_END()
