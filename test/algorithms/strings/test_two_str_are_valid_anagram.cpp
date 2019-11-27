#include <boost/test/unit_test.hpp>
#include "algorithms/strings/two_strings_are_valid_anagram.hpp"

BOOST_AUTO_TEST_SUITE(CheckIfStringIsAnagramOfOtherString)

BOOST_AUTO_TEST_CASE(empty_str)
{
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("", ""));
}

BOOST_AUTO_TEST_CASE(same_strings)
{
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("cat", "cat"));
}

BOOST_AUTO_TEST_CASE(valid_anagram)
{
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("anagram", "nagaram"));
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("restful", "fluster"));
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("funeral", "real fun"));
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("231", "1 2 3"));
}

BOOST_AUTO_TEST_CASE(invalid_anagram)
{
    BOOST_CHECK(!ValidAnagram::Solution::isAnagram("", "1"));
    BOOST_CHECK(!ValidAnagram::Solution::isAnagram("cat", "dog"));
    BOOST_CHECK(!ValidAnagram::Solution::isAnagram("real", "rea"));
}

BOOST_AUTO_TEST_SUITE_END()
