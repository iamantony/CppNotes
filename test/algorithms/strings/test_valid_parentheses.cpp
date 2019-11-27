#include <boost/test/unit_test.hpp>
#include "algorithms/strings/valid_parentheses.hpp"

BOOST_AUTO_TEST_SUITE(TestValidParentheses)

BOOST_AUTO_TEST_CASE(empty_string)
{
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid(std::string()));
}

BOOST_AUTO_TEST_CASE(valid_strings)
{
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("()"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("()[]{}"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("()()"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("(([{}]))"));
    BOOST_CHECK(Algo::Strings::ValidParentheses::IsValid("([({[]})])"));
}

BOOST_AUTO_TEST_CASE(invalid_strings)
{
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid(")("));
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid("()("));
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid("]{"));
    BOOST_CHECK(!Algo::Strings::ValidParentheses::IsValid("([)]"));
}

BOOST_AUTO_TEST_SUITE_END()
