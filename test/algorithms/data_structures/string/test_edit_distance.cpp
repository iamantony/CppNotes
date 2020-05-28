#include <boost/test/unit_test.hpp>
#include "algorithms/data_structures/string/edit_distance.hpp"

BOOST_AUTO_TEST_SUITE(TestEditDistance)

BOOST_AUTO_TEST_CASE(invalid_input) {
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("", "") == 0);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("ab", "") == 2);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("", "c") == 1);
}

BOOST_AUTO_TEST_CASE(valid_input) {
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("a", "a") == 0);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("ab", "ab") == 0);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("short", "ports") == 3);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("editing", "distance") == 5);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("horse", "ros") == 3);
    BOOST_CHECK(Algo::DS::String::EditDistance::Calc("intention", "execution") == 5);
}

BOOST_AUTO_TEST_SUITE_END()
