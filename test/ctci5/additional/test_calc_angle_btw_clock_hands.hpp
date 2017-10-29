#ifndef TEST_CALC_ANGLE_BTW_CLOCK_HANDS_HPP_
#define TEST_CALC_ANGLE_BTW_CLOCK_HANDS_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>
#include "../../common/utils.hpp"

#include "ctci5/additional/calc_angle_btw_clock_hands.hpp"

BOOST_AUTO_TEST_CASE(test_hands_angle_calculation_invalid)
{
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(-1, 4), 0.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(10, -90), 0.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(13, -3600), 0.0));
}

BOOST_AUTO_TEST_CASE(test_hands_angle_calculation)
{
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(0, 0), 0.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(12, 60), 0.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(1, 0), 30.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(0, 1), 5.5));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(5, 24), 18.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(2, 20), 50.0));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(4, 15), 37.5));
    BOOST_CHECK(areEqual(CalcAngleBtwClockHands(10, 43), 63.5));
}

#endif /* TEST_CALC_ANGLE_BTW_CLOCK_HANDS_HPP_ */
