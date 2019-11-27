#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include "algorithms/strings/str_unique_char.hpp"

BOOST_AUTO_TEST_SUITE(CheckIsStringHasOnlyUniqueCharcters)

BOOST_AUTO_TEST_CASE(empty_str)
{
    BOOST_CHECK(IsStrHasAllUniqueCharsBool(std::string()));
    BOOST_CHECK(IsStrHasAllUniqueCharsSet(std::string()));
    BOOST_CHECK(IsStrHasAllUniqueCharsSort(std::string()));
}

BOOST_AUTO_TEST_CASE(one_char)
{
    std::string str("e");
    BOOST_CHECK(IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_CASE(unique_chars)
{
    std::string str("euriwvjop");
    BOOST_CHECK(IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_CASE(not_unique_chars)
{
    std::string str("eupriowevjop");
    BOOST_CHECK(false == IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(false == IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(false == IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_SUITE_END()
