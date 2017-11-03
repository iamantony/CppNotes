#ifndef TEST_LONGEST_PALINDROME_HPP
#define TEST_LONGEST_PALINDROME_HPP

#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/strings/longest_palindrome.hpp"

BOOST_AUTO_TEST_CASE(test_lngpalindrom_empty_str)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("") == "");
}

BOOST_AUTO_TEST_CASE(test_lngpalindrom_str_one_char)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("a") == "a");
}

BOOST_AUTO_TEST_CASE(test_lngpalindrom_str_two_diff_chars)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("ab") == "b");
}

BOOST_AUTO_TEST_CASE(test_lngpalindrom_str_two_same_chars)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("aa") == "aa");
}

BOOST_AUTO_TEST_CASE(test_lngpalindrom_str_is_palindrom)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("abba") == "abba");
}

BOOST_AUTO_TEST_CASE(test_lngpalindrom_str_palindrom_in_the_middle)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("hjabbayu") == "abba");
}

BOOST_AUTO_TEST_CASE(test_lngpalindrom_str_two_palindroms)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("aabba") == "abba");
}

#endif // TEST_LONGEST_PALINDROME_HPP
