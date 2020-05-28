#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/sum_of_binary_strings.hpp"

BOOST_AUTO_TEST_SUITE(CalcSumOfBinaryNumsAsString)

BOOST_AUTO_TEST_CASE(empty_strings)
{
    BOOST_CHECK("0" == Algo::DS::String::AddBinaryStrings::Add("", ""));
}

BOOST_AUTO_TEST_CASE(one_empty_string)
{
    BOOST_CHECK("0" == Algo::DS::String::AddBinaryStrings::Add("0", ""));
    BOOST_CHECK("1" == Algo::DS::String::AddBinaryStrings::Add("", "1"));
    BOOST_CHECK("110" == Algo::DS::String::AddBinaryStrings::Add("110", ""));
}

BOOST_AUTO_TEST_CASE(small_strings)
{
    BOOST_CHECK("0" == Algo::DS::String::AddBinaryStrings::Add("0", "0"));
    BOOST_CHECK("1" == Algo::DS::String::AddBinaryStrings::Add("1", "0"));
    BOOST_CHECK("1" == Algo::DS::String::AddBinaryStrings::Add("0", "1"));
    BOOST_CHECK("10" == Algo::DS::String::AddBinaryStrings::Add("1", "1"));
}

BOOST_AUTO_TEST_CASE(leetcode_cases)
{
    BOOST_CHECK("100" == Algo::DS::String::AddBinaryStrings::Add("11", "1"));
}

BOOST_AUTO_TEST_SUITE_END()
