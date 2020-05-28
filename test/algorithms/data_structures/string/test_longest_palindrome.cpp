#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/longest_palindrome.hpp"

BOOST_AUTO_TEST_SUITE(FindLongestPalindromInString)

BOOST_AUTO_TEST_CASE(empty_str)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("") == "");
}

BOOST_AUTO_TEST_CASE(str_one_char)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("a") == "a");
}

BOOST_AUTO_TEST_CASE(str_two_diff_chars)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("ab") == "b");
}

BOOST_AUTO_TEST_CASE(str_two_same_chars)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("aa") == "aa");
}

BOOST_AUTO_TEST_CASE(str_is_palindrom)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("abba") == "abba");
}

BOOST_AUTO_TEST_CASE(str_palindrom_in_the_middle)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("hjabbayu") == "abba");
}

BOOST_AUTO_TEST_CASE(str_two_palindroms)
{
    Algo::DS::String::LongestPalindrome solution;
    BOOST_CHECK(solution.find("aabba") == "abba");
}

BOOST_AUTO_TEST_SUITE_END()
