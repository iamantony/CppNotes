#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/str_replace_spaces.hpp"

BOOST_AUTO_TEST_SUITE(ReplaceSpacesInString)

BOOST_AUTO_TEST_CASE(empty_data)
{
    char str[] = " ";
    Algo::DS::String::ReplaceSpaces(str);

    char expected[] = " ";
    BOOST_CHECK(0 == strncmp(str, expected, 1));
}

BOOST_AUTO_TEST_CASE(no_spaces)
{
    char str[] = "abc\0   ";
    Algo::DS::String::ReplaceSpaces(str);

    char expected[] = "abc\0   ";
    BOOST_CHECK(0 == strncmp(str, expected, 3));
}

BOOST_AUTO_TEST_CASE(spaces)
{
    char str[] = "ab c 56 dfg g \0          ";
    Algo::DS::String::ReplaceSpaces(str);

    char expected[] = "ab%20c%2056%20dfg%20g%20\0";
    BOOST_CHECK(0 == strncmp(str, expected, 24));
}

BOOST_AUTO_TEST_SUITE_END()
