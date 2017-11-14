#ifndef TEST_RANSOME_NOTE_HPP_
#define TEST_RANSOME_NOTE_HPP_

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/ransome_note.hpp"

BOOST_AUTO_TEST_CASE(test_rn_empty_data)
{
    BOOST_CHECK(false == isStrFormedFromStr("", ""));
    BOOST_CHECK(false == isStrFormedFromStr("abc", ""));
    BOOST_CHECK(false == isStrFormedFromStr("", "abc"));
}

BOOST_AUTO_TEST_CASE(test_rn_true_case)
{
    BOOST_CHECK(isStrFormedFromStr("kljjjjoiurt",
            "eopwkl fyujfe jetjwzjqo iu123rt"));
}

BOOST_AUTO_TEST_CASE(test_rn_false_case)
{
    BOOST_CHECK(false == isStrFormedFromStr(
            "abcdefcgh", "abcdiopert dsf e123"));
}

#endif /* TEST_RANSOME_NOTE_HPP_ */
