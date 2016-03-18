#ifndef TEST_STR_UNIQUE_CHAR_HPP_
#define TEST_STR_UNIQUE_CHAR_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "ctci5/data_structs/str_unique_char.hpp"

BOOST_AUTO_TEST_CASE(test_ishauc_empty_str)
{
    std::string empty_str;
    BOOST_CHECK(false == IsStrHasAllUniqueChars(empty_str));
}

#endif /* TEST_STR_UNIQUE_CHAR_HPP_ */
