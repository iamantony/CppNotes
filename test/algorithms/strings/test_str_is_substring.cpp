#include <boost/test/unit_test.hpp>
#include "algorithms/strings/str_is_substring.hpp"

BOOST_AUTO_TEST_SUITE(CheckIfStringIsSubstringOfOtherString)

BOOST_AUTO_TEST_CASE(empty_str)
{
    StrSubstring::Solution solution;
    BOOST_CHECK(0 == solution.strStr("", ""));
    BOOST_CHECK(0 == solution.strStr("abc", ""));
    BOOST_CHECK(-1 == solution.strStr("", "ght"));
    BOOST_CHECK(-1 == solution.strStr("ab", "cde"));
    BOOST_CHECK(-1 == solution.strStr("ab567", "cde"));

    BOOST_CHECK(false == solution.isStrRotationOfOtherStr("", ""));
    BOOST_CHECK(false == solution.isStrRotationOfOtherStr("abc", ""));
    BOOST_CHECK(false == solution.isStrRotationOfOtherStr("", "ght"));
    BOOST_CHECK(false == solution.isStrRotationOfOtherStr("ab", "cde"));
    BOOST_CHECK(false == solution.isStrRotationOfOtherStr("ab567", "cde"));
}

BOOST_AUTO_TEST_CASE(equal_size)
{
    StrSubstring::Solution solution;
    BOOST_CHECK(0 == solution.strStr("abc", "abc"));
    BOOST_CHECK(-1 == solution.strStr("abc", "cba"));
}

BOOST_AUTO_TEST_CASE(is_substring)
{
    StrSubstring::Solution solution;
    BOOST_CHECK(1 == solution.strStr("abcde", "bc"));
    BOOST_CHECK(0 == solution.strStr("abcde", "a"));
    BOOST_CHECK(4 == solution.strStr("abcde", "e"));
    BOOST_CHECK(-1 == solution.strStr("abcde", "bec"));
    BOOST_CHECK(-1 == solution.strStr("abcde", "0"));
    BOOST_CHECK(-1 == solution.strStr("abcde", "ef"));
    BOOST_CHECK(4 == solution.strStr("mississippi", "issip"));
}

BOOST_AUTO_TEST_CASE(is_rotation)
{
    StrSubstring::Solution solution;
    BOOST_CHECK(solution.isStrRotationOfOtherStr("abc", "cab"));
    BOOST_CHECK(solution.isStrRotationOfOtherStr("waterbottle", "erbottlewat"));
    BOOST_CHECK(false == solution.isStrRotationOfOtherStr("abc", "cba"));
}

BOOST_AUTO_TEST_SUITE_END()
