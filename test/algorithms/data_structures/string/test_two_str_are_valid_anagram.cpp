#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/two_strings_are_valid_anagram.hpp"

BOOST_AUTO_TEST_SUITE(CheckIfStringIsAnagramOfOtherString)

BOOST_AUTO_TEST_CASE(empty_str)
{
    BOOST_CHECK(Algo::DS::String::ValidAnagram::isAnagram("", ""));
}

BOOST_AUTO_TEST_CASE(same_strings)
{
    BOOST_CHECK(Algo::DS::String::ValidAnagram::isAnagram("cat", "cat"));
}

BOOST_AUTO_TEST_CASE(valid_anagram)
{
    BOOST_CHECK(Algo::DS::String::ValidAnagram::isAnagram("anagram", "nagaram"));
    BOOST_CHECK(Algo::DS::String::ValidAnagram::isAnagram("restful", "fluster"));
    BOOST_CHECK(Algo::DS::String::ValidAnagram::isAnagram("funeral", "real fun"));
    BOOST_CHECK(Algo::DS::String::ValidAnagram::isAnagram("231", "1 2 3"));
}

BOOST_AUTO_TEST_CASE(invalid_anagram)
{
    BOOST_CHECK(!Algo::DS::String::ValidAnagram::isAnagram("", "1"));
    BOOST_CHECK(!Algo::DS::String::ValidAnagram::isAnagram("cat", "dog"));
    BOOST_CHECK(!Algo::DS::String::ValidAnagram::isAnagram("real", "rea"));
}

BOOST_AUTO_TEST_SUITE_END()
