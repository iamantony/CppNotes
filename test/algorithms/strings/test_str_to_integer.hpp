#ifndef TEST_STR_TO_INTEGER_HPP
#define TEST_STR_TO_INTEGER_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/str_to_integer.hpp"

BOOST_AUTO_TEST_CASE(test_stint_empty_string)
{
    StrToInt::Solution solution;
    BOOST_CHECK(0 == solution.myAtoi(""));
    BOOST_CHECK(0 == solution.myAtoi(" "));
    BOOST_CHECK(0 == solution.myAtoi("    "));
}

BOOST_AUTO_TEST_CASE(test_stint_valid_number_in_string)
{
    StrToInt::Solution solution;
    BOOST_CHECK(1 == solution.myAtoi("1"));
    BOOST_CHECK(123 == solution.myAtoi("123"));
    BOOST_CHECK(5678 == solution.myAtoi("  5678"));
}

BOOST_AUTO_TEST_CASE(test_stint_negative_number)
{
    StrToInt::Solution solution;
    BOOST_CHECK(-999 == solution.myAtoi("-999"));
    BOOST_CHECK(979 == solution.myAtoi("+979"));
    BOOST_CHECK(-9 == solution.myAtoi(" -09"));
    BOOST_CHECK(-1908 == solution.myAtoi("    -1908"));
}

BOOST_AUTO_TEST_CASE(test_stint_string_with_non_digits)
{
    StrToInt::Solution solution;
    BOOST_CHECK(456 == solution.myAtoi(" 456!ayt"));
    BOOST_CHECK(-78 == solution.myAtoi("-78!9"));
    BOOST_CHECK(0 == solution.myAtoi("!12   "));
    BOOST_CHECK(0 == solution.myAtoi("-!12   "));
}

BOOST_AUTO_TEST_CASE(test_stint_huge_number)
{
    StrToInt::Solution solution;
    BOOST_CHECK(std::numeric_limits<int>::max() ==
                solution.myAtoi("9999999999999999999999999"));

    BOOST_CHECK(std::numeric_limits<int>::min() ==
                solution.myAtoi(" -88888888877777777776669"));
}

#endif // TEST_STR_TO_INTEGER_HPP
