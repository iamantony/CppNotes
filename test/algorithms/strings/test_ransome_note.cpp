#include <boost/test/unit_test.hpp>
#include "algorithms/strings/ransome_note.hpp"

BOOST_AUTO_TEST_SUITE(RansomNote)

BOOST_AUTO_TEST_CASE(empty_data)
{
    BOOST_CHECK(false == isStrFormedFromStr("", ""));
    BOOST_CHECK(false == isStrFormedFromStr("abc", ""));
    BOOST_CHECK(false == isStrFormedFromStr("", "abc"));
}

BOOST_AUTO_TEST_CASE(true_case)
{
    BOOST_CHECK(isStrFormedFromStr("kljjjjoiurt", "eopwkl fyujfe jetjwzjqo iu123rt"));
}

BOOST_AUTO_TEST_CASE(false_case)
{
    BOOST_CHECK(false == isStrFormedFromStr("abcdefcgh", "abcdiopert dsf e123"));
}

BOOST_AUTO_TEST_SUITE_END()
