#ifndef TEST_HAMMING_WEIGHT_HPP
#define TEST_HAMMING_WEIGHT_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/math/hamming_weight.hpp"

BOOST_AUTO_TEST_CASE(test_hw_str_empty_string)
{
    HammingWeight::Solution solution;
    BOOST_CHECK(0 == solution.HammingWeightForString(std::string()));
}

BOOST_AUTO_TEST_CASE(test_hw_str_non_empty_string)
{
    HammingWeight::Solution solution;
    BOOST_CHECK(1 == solution.HammingWeightForString("1"));
    BOOST_CHECK(1 == solution.HammingWeightForString("0"));
    BOOST_CHECK(1 == solution.HammingWeightForString("y"));
    BOOST_CHECK(1 == solution.HammingWeightForString("!"));
    BOOST_CHECK(7 == solution.HammingWeightForString("rty1:,."));
}

BOOST_AUTO_TEST_CASE(test_hw_str_zero_string)
{
    HammingWeight::Solution solution;
    BOOST_CHECK(0 == solution.HammingWeightForString(std::string(2, char(0))));
}

BOOST_AUTO_TEST_CASE(test_hw_int_null)
{
    HammingWeight::Solution solution;
    BOOST_CHECK(0 == solution.HammingWeightForInt(0));
}

BOOST_AUTO_TEST_CASE(test_hw_int_diff_values)
{
    HammingWeight::Solution solution;
    BOOST_CHECK(1 == solution.HammingWeightForInt(1));
    BOOST_CHECK(1 == solution.HammingWeightForInt(2));
    BOOST_CHECK(5 == solution.HammingWeightForInt(143));
    BOOST_CHECK(28 == solution.HammingWeightForInt(-143));
}

#endif // TEST_HAMMING_WEIGHT_HPP
