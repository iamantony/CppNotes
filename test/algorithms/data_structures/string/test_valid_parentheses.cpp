#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/valid_parentheses.hpp"

BOOST_AUTO_TEST_SUITE(TestValidParentheses)

BOOST_AUTO_TEST_CASE(empty_string)
{
    BOOST_CHECK(Algo::DS::String::ValidParentheses::IsValid(std::string()));
}

BOOST_AUTO_TEST_CASE(valid_strings)
{
    BOOST_CHECK(Algo::DS::String::ValidParentheses::IsValid("()"));
    BOOST_CHECK(Algo::DS::String::ValidParentheses::IsValid("()[]{}"));
    BOOST_CHECK(Algo::DS::String::ValidParentheses::IsValid("()()"));
    BOOST_CHECK(Algo::DS::String::ValidParentheses::IsValid("(([{}]))"));
    BOOST_CHECK(Algo::DS::String::ValidParentheses::IsValid("([({[]})])"));
}

BOOST_AUTO_TEST_CASE(invalid_strings)
{
    BOOST_CHECK(!Algo::DS::String::ValidParentheses::IsValid(")("));
    BOOST_CHECK(!Algo::DS::String::ValidParentheses::IsValid("()("));
    BOOST_CHECK(!Algo::DS::String::ValidParentheses::IsValid("]{"));
    BOOST_CHECK(!Algo::DS::String::ValidParentheses::IsValid("([)]"));
}

BOOST_AUTO_TEST_SUITE_END()
