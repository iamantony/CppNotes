#ifndef TEST_IS_NUMBER_POWER_OF_TWO_HPP
#define TEST_IS_NUMBER_POWER_OF_TWO_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/is_number_power_of_two.hpp"

BOOST_AUTO_TEST_CASE(test_inpot_power_of_two)
{
    NumberPowerOfTwo::Solution solution;
    BOOST_CHECK(solution.isPowerOfTwo(1) == true);
    BOOST_CHECK(solution.isPowerOfTwo(2) == true);
    BOOST_CHECK(solution.isPowerOfTwo(4) == true);
    BOOST_CHECK(solution.isPowerOfTwo(16) == true);
    BOOST_CHECK(solution.isPowerOfTwo(256) == true);
    BOOST_CHECK(solution.isPowerOfTwo(2048) == true);
}

BOOST_AUTO_TEST_CASE(test_inpot_not_power_of_two)
{
    NumberPowerOfTwo::Solution solution;
    BOOST_CHECK(solution.isPowerOfTwo(3) == false);
    BOOST_CHECK(solution.isPowerOfTwo(9) == false);
    BOOST_CHECK(solution.isPowerOfTwo(10) == false);
    BOOST_CHECK(solution.isPowerOfTwo(99) == false);
    BOOST_CHECK(solution.isPowerOfTwo(257) == false);
    BOOST_CHECK(solution.isPowerOfTwo(1000) == false);
}

#endif // TEST_IS_NUMBER_POWER_OF_TWO_HPP
