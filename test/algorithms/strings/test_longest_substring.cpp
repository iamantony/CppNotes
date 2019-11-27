#include <boost/test/unit_test.hpp>
#include "algorithms/strings/longest_substring.hpp"

BOOST_AUTO_TEST_SUITE(LengthOfLongestSubstring)

BOOST_AUTO_TEST_CASE(empty_str)
{
    LongestSubstring::Solution solution;
    BOOST_CHECK(solution.lengthOfLongestSubstring(std::string()) == 0);
}

BOOST_AUTO_TEST_CASE(simple_str)
{
    LongestSubstring::Solution solution;
    BOOST_CHECK(solution.lengthOfLongestSubstring("abc") == 3);
}

BOOST_AUTO_TEST_CASE(str_same_chars)
{
    LongestSubstring::Solution solution;
    BOOST_CHECK(solution.lengthOfLongestSubstring("bbbbbb") == 1);
}

BOOST_AUTO_TEST_CASE(str_with_several_substr)
{
    LongestSubstring::Solution solution;
    BOOST_CHECK(solution.lengthOfLongestSubstring("abcakdfcty") == 7);
}

BOOST_AUTO_TEST_SUITE_END()
