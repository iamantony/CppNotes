#ifndef TEST_EDIT_DISTANCE_HPP
#define TEST_EDIT_DISTANCE_HPP

#include <boost/test/unit_test.hpp>

#include "algorithms/strings/edit_distance.hpp"

BOOST_AUTO_TEST_CASE(test_eddist_invalid_input) {
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("", "") == 0);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("ab", "") == 2);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("", "c") == 1);
}

BOOST_AUTO_TEST_CASE(test_eddist_valid_input) {
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("a", "a") == 0);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("ab", "ab") == 0);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("short", "ports") == 3);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("editing", "distance") == 5);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("horse", "ros") == 3);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("intention", "execution") == 5);
}

#endif // TEST_EDIT_DISTANCE_HPP
