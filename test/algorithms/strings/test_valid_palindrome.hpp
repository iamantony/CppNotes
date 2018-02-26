#ifndef TEST_VALID_PALINDROME_HPP
#define TEST_VALID_PALINDROME_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/valid_palindrome.hpp"

BOOST_AUTO_TEST_CASE(test_valpal_empty_strings)
{
    ValidPalindrome::Solution solution;
    BOOST_CHECK(true == solution.isPalindrome(std::string()));
    BOOST_CHECK(true == solution.isPalindrome(" "));
}

BOOST_AUTO_TEST_CASE(test_valpal_simple_strings)
{
    ValidPalindrome::Solution solution;
    BOOST_CHECK(true == solution.isPalindrome("a"));
    BOOST_CHECK(true == solution.isPalindrome("aBa"));
    BOOST_CHECK(true == solution.isPalindrome("abba"));
    BOOST_CHECK(true == solution.isPalindrome(" a1,!"));
    BOOST_CHECK(true == solution.isPalindrome("a. "));
    BOOST_CHECK(true == solution.isPalindrome(".,"));
}

BOOST_AUTO_TEST_CASE(test_valpal_not_palindrome)
{
    ValidPalindrome::Solution solution;
    BOOST_CHECK(false == solution.isPalindrome("race a car"));
    BOOST_CHECK(false == solution.isPalindrome("abac"));
    BOOST_CHECK(false == solution.isPalindrome("0P"));
}

BOOST_AUTO_TEST_CASE(test_valpal_complex_strings)
{
    ValidPalindrome::Solution solution;
    BOOST_CHECK(true == solution.isPalindrome("A man, a plan, a canal: Panama"));
}

#endif // TEST_VALID_PALINDROME_HPP
