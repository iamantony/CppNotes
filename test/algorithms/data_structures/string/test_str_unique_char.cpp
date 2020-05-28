#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include "algorithms/data_structures/string/str_unique_char.hpp"

BOOST_AUTO_TEST_SUITE(CheckIsStringHasOnlyUniqueCharcters)

BOOST_AUTO_TEST_CASE(empty_str)
{
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsBool(std::string()));
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsSet(std::string()));
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsSort(std::string()));
}

BOOST_AUTO_TEST_CASE(one_char)
{
    std::string str("e");
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_CASE(unique_chars)
{
    std::string str("euriwvjop");
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(Algo::DS::String::IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_CASE(not_unique_chars)
{
    std::string str("eupriowevjop");
    BOOST_CHECK(false == Algo::DS::String::IsStrHasAllUniqueCharsBool(str));
    BOOST_CHECK(false == Algo::DS::String::IsStrHasAllUniqueCharsSet(str));
    BOOST_CHECK(false == Algo::DS::String::IsStrHasAllUniqueCharsSort(str));
}

BOOST_AUTO_TEST_SUITE_END()
