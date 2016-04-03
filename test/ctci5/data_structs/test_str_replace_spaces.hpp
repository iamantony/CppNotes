#ifndef TEST_STR_REPLACE_SPACES_HPP_
#define TEST_STR_REPLACE_SPACES_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "ctci5/data_structs/str_replace_spaces.hpp"

BOOST_AUTO_TEST_CASE(test_srs_empty_data)
{
    char str[] = " ";
    ReplaceSpaces(str);

    char expected[] = " ";
    BOOST_CHECK(0 == strncmp(str, expected, 1));
}

BOOST_AUTO_TEST_CASE(test_srs_no_spaces)
{
    char str[] = "abc\0   ";
    ReplaceSpaces(str);

    char expected[] = "abc\0   ";
    BOOST_CHECK(0 == strncmp(str, expected, 3));
}

BOOST_AUTO_TEST_CASE(test_srs_spaces)
{
    char str[] = "ab c 56 dfg g \0          ";
    ReplaceSpaces(str);

    char expected[] = "ab%20c%2056%20dfg%20g%20\0";
    BOOST_CHECK(0 == strncmp(str, expected, 24));
}

#endif /* TEST_STR_REPLACE_SPACES_HPP_ */
