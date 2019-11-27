#include <boost/test/unit_test.hpp>
#include "algorithms/strings/longest_palindrome.hpp"

BOOST_AUTO_TEST_SUITE(FindLongestPalindromInString)

BOOST_AUTO_TEST_CASE(empty_str)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("") == "");
}

BOOST_AUTO_TEST_CASE(str_one_char)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("a") == "a");
}

BOOST_AUTO_TEST_CASE(str_two_diff_chars)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("ab") == "b");
}

BOOST_AUTO_TEST_CASE(str_two_same_chars)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("aa") == "aa");
}

BOOST_AUTO_TEST_CASE(str_is_palindrom)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("abba") == "abba");
}

BOOST_AUTO_TEST_CASE(str_palindrom_in_the_middle)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("hjabbayu") == "abba");
}

BOOST_AUTO_TEST_CASE(str_two_palindroms)
{
    LongestPalindrome::Solution solution;
    BOOST_CHECK(solution.longestPalindrome("aabba") == "abba");
}

BOOST_AUTO_TEST_SUITE_END()
