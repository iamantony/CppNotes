#include <boost/test/unit_test.hpp>
#include "algorithms/math/is_number_power_of_two.hpp"

BOOST_AUTO_TEST_SUITE(CheckIsPowerOf2)

BOOST_AUTO_TEST_CASE(true_cases)
{
    NumberPowerOfTwo::Solution solution;
    BOOST_CHECK(solution.isPowerOfTwo(1) == true);
    BOOST_CHECK(solution.isPowerOfTwo(2) == true);
    BOOST_CHECK(solution.isPowerOfTwo(4) == true);
    BOOST_CHECK(solution.isPowerOfTwo(16) == true);
    BOOST_CHECK(solution.isPowerOfTwo(256) == true);
    BOOST_CHECK(solution.isPowerOfTwo(2048) == true);
}

BOOST_AUTO_TEST_CASE(false_cases)
{
    NumberPowerOfTwo::Solution solution;
    BOOST_CHECK(solution.isPowerOfTwo(3) == false);
    BOOST_CHECK(solution.isPowerOfTwo(9) == false);
    BOOST_CHECK(solution.isPowerOfTwo(10) == false);
    BOOST_CHECK(solution.isPowerOfTwo(99) == false);
    BOOST_CHECK(solution.isPowerOfTwo(257) == false);
    BOOST_CHECK(solution.isPowerOfTwo(1000) == false);
}

BOOST_AUTO_TEST_SUITE_END()
