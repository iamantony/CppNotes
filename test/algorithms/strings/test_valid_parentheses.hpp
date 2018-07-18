#ifndef TEST_VALID_PARENTHESES_HPP
#define TEST_VALID_PARENTHESES_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/valid_parentheses.hpp"

BOOST_AUTO_TEST_CASE(test_valpar_empty_string)
{
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid(std::string()));
}

BOOST_AUTO_TEST_CASE(test_valpar_valid_strings)
{
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("()"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("()[]{}"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("()()"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("(([{}]))"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("([({[]})])"));
}

BOOST_AUTO_TEST_CASE(test_valpar_invalid_strings)
{
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid(")("));
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid("()("));
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid("]{"));
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid("([)]"));
}

#endif // TEST_VALID_PARENTHESES_HPP
