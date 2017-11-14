#ifndef TEST_STR_REVERSE_HPP_
#define TEST_STR_REVERSE_HPP_

#include <boost/test/unit_test.hpp>

#include <string>
#include <algorithm>

#include "algorithms/strings/str_reverse.hpp"

BOOST_AUTO_TEST_CASE(test_str_rev_empty_str)
{
    char str[] = {'\0'};
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(test_str_rev_str_one_char)
{
    char str[] = "a";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(test_str_rev_str_two_char)
{
    char str[] = "ab";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(test_str_rev_str_even_size)
{
    char str[] = "123456";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(test_str_rev_str)
{
    char str[] = "abuui;jwljklkdfjhkj;$21";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

#endif /* TEST_STR_REVERSE_HPP_ */
