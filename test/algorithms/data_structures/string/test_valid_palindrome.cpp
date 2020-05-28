#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/valid_palindrome.hpp"

BOOST_AUTO_TEST_SUITE(CheckIfStringIsPalindrom)

BOOST_AUTO_TEST_CASE(empty_strings)
{
    Algo::DS::String::ValidPalindrome solution;
    BOOST_CHECK(true == solution.isPalindrome(std::string()));
    BOOST_CHECK(true == solution.isPalindrome(" "));
}

BOOST_AUTO_TEST_CASE(simple_strings)
{
    Algo::DS::String::ValidPalindrome solution;
    BOOST_CHECK(true == solution.isPalindrome("a"));
    BOOST_CHECK(true == solution.isPalindrome("aBa"));
    BOOST_CHECK(true == solution.isPalindrome("abba"));
    BOOST_CHECK(true == solution.isPalindrome("a. "));
    BOOST_CHECK(true == solution.isPalindrome(".,"));
}

BOOST_AUTO_TEST_CASE(not_palindrome)
{
    Algo::DS::String::ValidPalindrome solution;
    BOOST_CHECK(false == solution.isPalindrome("race a car"));
    BOOST_CHECK(false == solution.isPalindrome("abac"));
    BOOST_CHECK(false == solution.isPalindrome("0P"));
    BOOST_CHECK(false == solution.isPalindrome(" a1,!"));
}

BOOST_AUTO_TEST_CASE(complex_strings)
{
    Algo::DS::String::ValidPalindrome solution;
    BOOST_CHECK(true == solution.isPalindrome("A man, a plan, a canal: Panama"));
}

BOOST_AUTO_TEST_SUITE_END()
