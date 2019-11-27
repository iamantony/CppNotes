#include <boost/test/unit_test.hpp>
#include "algorithms/strings/edit_distance.hpp"

BOOST_AUTO_TEST_SUITE(TestEditDistance)

BOOST_AUTO_TEST_CASE(invalid_input) {
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("", "") == 0);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("ab", "") == 2);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("", "c") == 1);
}

BOOST_AUTO_TEST_CASE(valid_input) {
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("a", "a") == 0);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("ab", "ab") == 0);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("short", "ports") == 3);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("editing", "distance") == 5);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("horse", "ros") == 3);
    BOOST_CHECK(Algo::Strings::EditDistance::Calc("intention", "execution") == 5);
}

BOOST_AUTO_TEST_SUITE_END()
