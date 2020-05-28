#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/ransome_note.hpp"

BOOST_AUTO_TEST_SUITE(RansomNote)

BOOST_AUTO_TEST_CASE(empty_data)
{
    BOOST_CHECK(Algo::DS::String::isStrFormedFromStr("", ""));
    BOOST_CHECK(false == Algo::DS::String::isStrFormedFromStr("abc", ""));
    BOOST_CHECK(Algo::DS::String::isStrFormedFromStr("", "abc"));
}

BOOST_AUTO_TEST_CASE(true_case)
{
    BOOST_CHECK(Algo::DS::String::isStrFormedFromStr(
        "kljjjjoiurt", "eopwkl fyujfe jetjwzjqo iu123rt"));
}

BOOST_AUTO_TEST_CASE(false_case)
{
    BOOST_CHECK(false == Algo::DS::String::isStrFormedFromStr(
        "abcdefcgh", "abcdiopert dsf e123"));
}

BOOST_AUTO_TEST_SUITE_END()
