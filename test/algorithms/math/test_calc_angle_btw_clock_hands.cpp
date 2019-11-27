#include <boost/test/unit_test.hpp>
#include "common/equality.hpp"
#include "algorithms/math/calc_angle_btw_clock_hands.hpp"

BOOST_AUTO_TEST_SUITE(CalcAngleBetweenClockHands)

BOOST_AUTO_TEST_CASE(invalid_input)
{
    BOOST_CHECK(equal(CalcAngleBtwClockHands(-1, 4), 0.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(10, -90), 0.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(13, -3600), 0.0));
}

BOOST_AUTO_TEST_CASE(valid_input)
{
    BOOST_CHECK(equal(CalcAngleBtwClockHands(0, 0), 0.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(12, 60), 0.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(1, 0), 30.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(0, 1), 5.5));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(5, 24), 18.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(2, 20), 50.0));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(4, 15), 37.5));
    BOOST_CHECK(equal(CalcAngleBtwClockHands(10, 43), 63.5));
}

BOOST_AUTO_TEST_SUITE_END()
