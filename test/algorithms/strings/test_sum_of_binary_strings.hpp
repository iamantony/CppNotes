#ifndef TEST_SUM_OF_BINARY_STRINGS_HPP
#define TEST_SUM_OF_BINARY_STRINGS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/sum_of_binary_strings.hpp"

BOOST_AUTO_TEST_CASE(test_sobs_empty_strings)
{
    SumOfBinaryStrings::Solution solution;
    BOOST_CHECK("0" == solution.addBinary(std::string(), std::string()));
}

BOOST_AUTO_TEST_CASE(test_sobs_one_empty_string)
{
    SumOfBinaryStrings::Solution solution;
    BOOST_CHECK("0" == solution.addBinary("0", std::string()));
    BOOST_CHECK("1" == solution.addBinary(std::string(), "1"));

    BOOST_CHECK("110" == solution.addBinary("110", std::string()));
}

BOOST_AUTO_TEST_CASE(test_sobs_small_strings)
{
    SumOfBinaryStrings::Solution solution;
    BOOST_CHECK("0" == solution.addBinary("0", "0"));
    BOOST_CHECK("1" == solution.addBinary("1", "0"));
    BOOST_CHECK("1" == solution.addBinary("0", "1"));
    BOOST_CHECK("10" == solution.addBinary("1", "1"));
}

BOOST_AUTO_TEST_CASE(test_sobs_leetcode_cases)
{
    SumOfBinaryStrings::Solution solution;
    BOOST_CHECK("100" == solution.addBinary("11", "1"));
}

#endif // TEST_SUM_OF_BINARY_STRINGS_HPP
