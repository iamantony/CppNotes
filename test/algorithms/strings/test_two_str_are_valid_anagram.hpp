#ifndef TEST_TWO_STR_ARE_VALID_ANAGRAM_HPP
#define TEST_TWO_STR_ARE_VALID_ANAGRAM_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/two_strings_are_valid_anagram.hpp"

BOOST_AUTO_TEST_CASE(test_tsava_empty_str)
{
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("", ""));
}

BOOST_AUTO_TEST_CASE(test_tsava_same_strings)
{
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("cat", "cat"));
}

BOOST_AUTO_TEST_CASE(test_tsava_valid_anagram)
{
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("anagram", "nagaram"));
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("restful", "fluster"));
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("funeral", "real fun"));
    BOOST_CHECK(ValidAnagram::Solution::isAnagram("231", "1 2 3"));
}

BOOST_AUTO_TEST_CASE(test_tsava_invalid_anagram)
{
    BOOST_CHECK(!ValidAnagram::Solution::isAnagram("", "1"));
    BOOST_CHECK(!ValidAnagram::Solution::isAnagram("cat", "dog"));
    BOOST_CHECK(!ValidAnagram::Solution::isAnagram("real", "rea"));
}

#endif // TEST_TWO_STR_ARE_VALID_ANAGRAM_HPP
