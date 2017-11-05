#ifndef TEST_STR_IS_SUBSTRING_HPP_
#define TEST_STR_IS_SUBSTRING_HPP_

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/strings/str_is_substring.hpp"

BOOST_AUTO_TEST_CASE(test_sis_empty_str)
{
    BOOST_CHECK(false == isSubString("", ""));
    BOOST_CHECK(false == isSubString("abc", ""));
    BOOST_CHECK(false == isSubString("", "ght"));
    BOOST_CHECK(false == isSubString("ab", "cde"));

    BOOST_CHECK(false == isStrRotationOfOtherStr("", ""));
    BOOST_CHECK(false == isStrRotationOfOtherStr("abc", ""));
    BOOST_CHECK(false == isStrRotationOfOtherStr("", "ght"));
    BOOST_CHECK(false == isStrRotationOfOtherStr("ab", "cde"));
    BOOST_CHECK(false == isStrRotationOfOtherStr("ab567", "cde"));
}

BOOST_AUTO_TEST_CASE(test_sis_equal_size)
{
    BOOST_CHECK(isSubString("abc", "abc"));
    BOOST_CHECK(false == isSubString("abc", "cba"));
}

BOOST_AUTO_TEST_CASE(test_sis_is_substring)
{
    BOOST_CHECK(isSubString("abcde", "bc"));
    BOOST_CHECK(isSubString("abcde", "a"));
    BOOST_CHECK(isSubString("abcde", "e"));
    BOOST_CHECK(false == isSubString("abcde", "bec"));
    BOOST_CHECK(false == isSubString("abcde", "0"));
    BOOST_CHECK(false == isSubString("abcde", "ef"));
}

BOOST_AUTO_TEST_CASE(test_sis_is_rotation)
{
    BOOST_CHECK(isStrRotationOfOtherStr("abc", "cab"));
    BOOST_CHECK(isStrRotationOfOtherStr("waterbottle", "erbottlewat"));
    BOOST_CHECK(false == isStrRotationOfOtherStr("abc", "cba"));
}

#endif /* TEST_STR_IS_SUBSTRING_HPP_ */
