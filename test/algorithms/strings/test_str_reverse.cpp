#include <boost/test/unit_test.hpp>
#include <string>
#include <algorithm>
#include "algorithms/strings/str_reverse.hpp"

BOOST_AUTO_TEST_SUITE(TestReverseString)

BOOST_AUTO_TEST_CASE(empty_str)
{
    char str[] = {'\0'};
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(str_one_char)
{
    char str[] = "a";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(str_two_char)
{
    char str[] = "ab";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(str_even_size)
{
    char str[] = "123456";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_CASE(long_str)
{
    char str[] = "abuui;jwljklkdfjhkj;$21";
    std::string expected(str);
    std::reverse(expected.begin(), expected.end());

    ReverseString(str);

    BOOST_CHECK(std::string(str) == expected);
}

BOOST_AUTO_TEST_SUITE_END()
