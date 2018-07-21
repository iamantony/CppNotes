#ifndef TEST_SUM_OF_BINARY_STRINGS_HPP
#define TEST_SUM_OF_BINARY_STRINGS_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/sum_of_binary_strings.hpp"

BOOST_AUTO_TEST_CASE(test_sobs_empty_strings)
{
    BOOST_CHECK("0" == Algo::Strings::AddBinaryStrings::Add("", ""));
}

BOOST_AUTO_TEST_CASE(test_sobs_one_empty_string)
{
    BOOST_CHECK("0" == Algo::Strings::AddBinaryStrings::Add("0", ""));
    BOOST_CHECK("1" == Algo::Strings::AddBinaryStrings::Add("", "1"));
    BOOST_CHECK("110" == Algo::Strings::AddBinaryStrings::Add("110", ""));
}

BOOST_AUTO_TEST_CASE(test_sobs_small_strings)
{
    BOOST_CHECK("0" == Algo::Strings::AddBinaryStrings::Add("0", "0"));
    BOOST_CHECK("1" == Algo::Strings::AddBinaryStrings::Add("1", "0"));
    BOOST_CHECK("1" == Algo::Strings::AddBinaryStrings::Add("0", "1"));
    BOOST_CHECK("10" == Algo::Strings::AddBinaryStrings::Add("1", "1"));
}

BOOST_AUTO_TEST_CASE(test_sobs_leetcode_cases)
{
    BOOST_CHECK("100" == Algo::Strings::AddBinaryStrings::Add("11", "1"));
}

#endif // TEST_SUM_OF_BINARY_STRINGS_HPP
