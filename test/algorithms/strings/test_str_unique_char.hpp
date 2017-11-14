#ifndef TEST_STR_UNIQUE_CHAR_HPP_
#define TEST_STR_UNIQUE_CHAR_HPP_

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "algorithms/strings/str_unique_char.hpp"

BOOST_AUTO_TEST_CASE(test_ishauc_empty_str)
{
    BOOST_CHECK(IsStrHasAllUniqueCharsBool(std::string()));
    BOOST_CHECK(IsStrHasAllUniqueCharsSet(std::string()));
    BOOST_CHECK(IsStrHasAllUniqueCharsSort(std::string()));
}

BOOST_AUTO_TEST_CASE(test_ishauc_one_char)
{
    std::string str("e");
    BOOST_CHECK(IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_CASE(test_ishauc_unique_chars)
{
    std::string str("euriwvjop");
    BOOST_CHECK(IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_CASE(test_ishauc_not_unique_chars)
{
    std::string str("eupriowevjop");
    BOOST_CHECK(false == IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(false == IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(false == IsStrHasAllUniqueCharsSort(str));
}

#endif /* TEST_STR_UNIQUE_CHAR_HPP_ */
